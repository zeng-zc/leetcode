// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <stdio.h>
/* 算法：
 * 对于当前字符，要维持一个 start 变量和一个 prepos 变量，
 * prepos 变量记录当前字符前一次出现的位置。如果 prepos < start,
 * 则start不用变，当前长度加1；否则，prepos在start之后，则
 * 下一次迭代的 start 要更新为 prepos+1.
 */ 
int lengthOfLongestSubstring(char* s) {
    int prepos, position[128], start=0, curLen=0, longest=0;
    for(int i=0; i<128; i++)
        position[i]=-1; // 赋初值为-1（注意不能为0）
    for(int i=0; s[i]; i++){
        prepos = position[s[i]];
        if(prepos < start)
            curLen++;
        else{
            curLen = i - prepos;
            start = prepos +1;
        }
        position[s[i]] = i;
        longest = (longest > curLen) ? longest : curLen;
    }
    return longest;
}

int main(){
    char *s="abcdec";
    printf("s=%s, res=%d\n", s, lengthOfLongestSubstring(s));
    return 0;
}

// accepted.
