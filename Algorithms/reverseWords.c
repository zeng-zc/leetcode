// https://leetcode.com/problems/reverse-words-in-a-string/
/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing
spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Algorithm:
// first pass: reverse word and remove duplicate spaces (removing dup spaces
//             can also be a seperate pass).
// second pass: reverse character one by one
// for example: /i love   leetcode/ -> /i evol edocteel/ -> /leetcode love i/
void reverse (char *s, int beg, int end);
void removeDupSpace(char *s);

void reverseWords(char *s) {
    int beg=0, end=0, hasSpace=0;
    char *cur=s;
    removeDupSpace(s);
    size_t len=0;
    for(; *cur; len++){
        if(isspace(*cur)){
            hasSpace=1;
            end = cur-1-s;
            reverse(s, beg, end);
            beg = (++cur) - s;
        }else
            cur++;
    }
    if(hasSpace==1) {
        end = cur-1-s; // process last word.
        reverse(s, beg, end);
        reverse(s, 0, len-1);
    // No need to reverse if only one word.
    }
}

void reverse (char *s, int beg, int end){
    for(int i=beg, j=end; i<j; i++, j--){
        char tmp=s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

// remove duplicate spaces.
void removeDupSpace(char *s){
    char *dsc=s, *cur=s, *pre=NULL;
    while(*cur){
        if(isspace(*cur) && (pre == NULL || isspace(*pre))){
                pre = cur;
                cur++;
        }else{
            pre = cur;
            *dsc++ = *cur++;
        }
    }
    // removing one trailing space(if any)
    if(dsc-s>0 && isspace(*(dsc-1)))
        *--dsc='\0';
    else
        *dsc='\0';
}

int main(){
    char s[]=" we love   leetcode  ";
    printf("original s: /%s/\n", s);
    reverseWords(s);
    printf("after s: /%s/\n", s);
    char s2[]="  leetcode  ";
    printf("original s2: /%s/\n", s2);
    reverseWords(s2);
    printf("after s2: /%s/\n", s2);
    return 0;
}

