## https://leetcode.com/problems/transpose-file/
perl -ane 'push @res, @F; 
END{
    for($i=0; $i<@F; $i++){
        undef(@tmp);
        for($j=$i; $j<@res; $j+=@F){
            push @tmp, @res[$j];
        } 
        print "@tmp\n";
    }
}'

## 在 leetcode 上，多输出一个空格都不行。
## 因此，第二个 for 循环中，不能这样输出： print "$res[$j] ",
## 因为这样每行最后会多出一个空格
