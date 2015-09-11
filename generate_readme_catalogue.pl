#!/usr/bin/perl -w
use warnings;
use strict;
use HTTP::Tiny;
use v5.16;  ## say

my $url = 'https://leetcode.com/problemset/algorithms/';
#my $url = 'file:///Users/zengzc/programming/leetcode/script/Problems | LeetCode OJ.html';
my $response = HTTP::Tiny->new->get($url);
#print $response;
die "Failed!\n" unless $response->{success};
#print "$response->{status} $response->{reason}\n";

my $html = $response->{content};
#print $html;
die "No html in \$html!\n" unless length $html;

## get answer files and corresponding url.
my $dir = './Algorithms';
opendir(my $dh, $dir) || die "can't opendir $dir: $!";
my %answers;  ## key=filename, value=url;
while(readdir $dh){
    if(lc $_ =~ /(cpp|c|py)$/){
        open my $ansfh, '<', "$dir/$_" or die $!;
        my $url;
        while(my $line = <$ansfh>){
            $url = $1 if($line =~ m/(https:.*$)/);
            last if $.==3;
        }
        close $ansfh;
        $answers{$_} = $url if(defined($url));
    }
}
close $dh;

# generate result file.
#open my $fh, ">", "readme.md.catalogue";
my $fh =*STDOUT;
say $fh "# Catalogue";
say $fh " No.|  # | Title | Difficulty | Solution";
say $fh " ----|----|-------------|-----------|--------";
my $count=0;
while($html =~ m{<td>(?<num>\d+)</td>.*?<a href="(?<loc>.*?)">(?<title>.*?)</a>.*?<td value='\d'>(?<difficulty>\w+)</td>}smg){
    my ($num, $loc, $title, $difficulty) = ($1, $2, $3, $4);
    $loc = 'https://leetcode.com'.$2;
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
            }
            say $fh "$count\t| $num\t | [$title]($loc)\t| $difficulty\t| [$language]($dir/$_)";
        }
    }
}
close $fh;

=pod
    print "\$num=${num}\n";
    print "\$loc=${loc}\n";
    print "\$title=${title}\n";
    print "\$difficulty=${difficulty}\n";
=cut


