// https://leetcode.com/problems/length-of-last-word/
/*
Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space
characters only.

For example,
Given s = "Hello World",
return 5. 
*/

#include <stdio.h>
int lengthOfLastWord(char* s) {
    char *word_beg=NULL, *word_end;
    char *p=s;
    char *next;
    while(*p){
        next = p+1;
        if(*p == ' ')
            p = next;
        else{
            word_beg = p;
            while(isalpha(*next)){
                p = next;
                next++;
            }
            word_end = p;
            p=next;
        }
    }
    if(word_beg == NULL)
        return 0;
    else
        return word_end - word_beg + 1;
}


int main(){
    char *s1="hello world";
    char *s2="hello world ";
    char *s3="   ";
    printf("%s, %d\n", s1, lengthOfLastWord(s1));
    printf("%s, %d\n", s2, lengthOfLastWord(s2));
    printf("%s, %d\n", s3, lengthOfLastWord(s3));
    return 0;
}

