#!/usr/bin/perl -w
use warnings;
use strict;
use HTTP::Tiny;
use v5.16;  ## say
use Storable qw /nstore retrieve/;

my $serilized_file="packed.bin"; ## 索引文件的序列化，用于增量建索引

## input: url; output: html
sub get_html_content {
    my $url = shift;
    my $response = HTTP::Tiny->new->get($url);
    #print $response;
    warn "Failed!\n" and return "FAIL" unless $response->{success};
    print "$url: $response->{status} $response->{reason}\n";

    my $doc = $response->{content};
    #print $html;
    warn "No html in \$doc!\n" and return "FAIL" unless length $doc;
    return \$doc;
}

## input: html; output: number, title, difficulty
sub parse_html {
    my $html = shift; ## reference
    my ($num, $title, $difficulty);
    if ($$html =~ m{questionId: '(.*?)'}) {
        $num = $1;
    }
    if ($$html =~ m{<title>(.*?) \| LeetCode OJ</title>}) {
        $title = $1;
    }
    if ($$html =~ m{<li>Difficulty: <strong>(.*?)</strong></li>}) {
        $difficulty = $1;
    }
    return ($num, $title, $difficulty);
}

## get answer files and corresponding url.
sub parse_answer_files {
    my %answers;  ## key=filename, value=url;
    my @dirs = qw \./Algorithms ./Shell\;
    for my $dir (@dirs){
        opendir(my $dh, $dir) || die "can't opendir $dir: $!";
        while(readdir $dh){
            if(lc $_ =~ /(cpp|c|py|sh|pl)$/){
                open my $ansfh, '<', "$dir/$_" or die $!;
                my $url;
                while(my $line = <$ansfh>){
                    $url = $1 if($line =~ m/(https:.*$)/);
                    last if $.==3;
                }
                close $ansfh;
                $answers{"$dir/$_"} = $url if(defined($url));
            }
        }
        close $dh;
    }
    say "Having obtained URL from solution files.";
    return \%answers;
}

# generate result file.
sub build_index_table {
    my $index_table; ## ref to hash of array
    if (-e $serilized_file) {
        $index_table = retrieve $serilized_file;
    }
    my $answers = &parse_answer_files;
    for(keys %$answers){
        say "$_ exist in $serilized_file!" and next if exists $index_table->{$_}; ##  has indexed already

        my $url = $answers->{$_};
##        say $url;
        my $htmlref = &get_html_content($url); 
        say "FAIL" and next if $$htmlref eq "FAIL";
        my @result = &parse_html($htmlref); 
        my ($num, $title, $difficulty) = @result;
        my $language;
        if(lc $_ =~ /\.cpp$/){
            $language="C++";
        }elsif (lc $_ =~ /\.c$/){
            $language = "C";
        }elsif (lc $_ =~ /\.py$/){
            $language = "Python";
        }elsif (lc $_ =~ /\.sh$/){
            $language = "Shell";
        }elsif (lc $_ =~ /\.pl$/){
            $language = "Perl";
        }
        $index_table->{$_} = [$num, $title, $url, $difficulty, $language, $_]; ## insert into index table
        say "add $_ to $serilized_file";
    }

    for(keys %$index_table){
        delete $index_table->{$_} and say "delete $_ from $serilized_file" if not exists $answers->{$_};
    }

    nstore $index_table, $serilized_file;
    return $index_table;
}

sub output {
    my $index_table = &build_index_table;
    my @sorted_keys = sort {
            $index_table->{$a}->[0] <=> $index_table->{$b}->[0]
        } keys %$index_table;
    open my $fh, ">>", "README.md";
    say $fh "# Catalogue";
    say $fh " No.| # in leetcode | Title | Difficulty | Solution";
    say $fh " ----|---------------|-------------|-----------|--------";
    my $count = 1;
    foreach (@sorted_keys) {
        my ($num, $title, $url, $difficulty, $language) = @{$index_table->{$_}};
        say $fh "$count\t| $num\t | [$title]($url)\t| $difficulty\t| [$language]($_)";
#        say STDOUT "$count\t| $num\t | [$title]($url)\t| $difficulty\t| [$language]($_)";
        $count++;
    }
    close $fh;
}

&output;
