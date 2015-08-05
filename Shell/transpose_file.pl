## https://leetcode.com/problems/transpose-file/
while (<>){
    @F=split(' ');
    push @res, @F; 
}
$len=@F;
#print "len=$len\n";
#print "res length =", scalar @res, " \n";
for($i=0; $i<$len; $i++){
    for($j=$i; $j<@res; $j=$j+$len){
        print "$res[$j] ";
    } 
    print "\n";
}

