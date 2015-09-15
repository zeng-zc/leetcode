#!/usr/bin/perl -w
use warnings;
use strict;
use HTTP::Tiny;
use v5.16;  ## say

my @urls = qw\https://leetcode.com/problemset/algorithms 
    https://leetcode.com/problemset/shell/\;
my $html;
for my $url (@urls){
    my $response = HTTP::Tiny->new->get($url);
#print $response;
    die "Failed!\n" unless $response->{success};
print "$url: $response->{status} $response->{reason}\n";

    my $doc = $response->{content};
#print $html;
    die "No html in \$doc!\n" unless length $doc;
    $html = $html.$doc;
}

## get answer files and corresponding url.
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

# generate result file.
open my $fh, ">>", "README.md";
#my $fh =*STDOUT;
say $fh "# Catalogue";
say $fh " No.|  # | Title | Difficulty | Solution";
say $fh " ----|----|-------------|-----------|--------";
my $count=0;
while($html =~ m{<td>(\d+)</td>.*?<a href="(.*?)">(.*?)</a>.*?<td value='.*?'>(\w+)</td>}smg){
    my ($num, $loc, $title, $difficulty) = ($1, $2, $3, $4);
    $loc = 'https://leetcode.com'.$2;
#    say STDOUT "$num\n $loc\n$title\n$difficulty";
    for(keys %answers){
        if($loc =~ $answers{$_}){
            $count++;
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
            say $fh "$count\t| $num\t | [$title]($loc)\t| $difficulty\t| [$language]($_)";
            say STDOUT "$count\t| $num\t | [$title]($loc)\t| $difficulty\t| [$language]($_)";
        }
    }
}
close $fh;

