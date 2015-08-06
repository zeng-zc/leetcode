// https://leetcode.com/problems/implement-strstr/
/*
 *  Implement strStr().
 *
 *  Returns the index of the first occurrence of needle in haystack, or -1 if
 *  needle is not part of haystack. 
 */
#include <stdio.h>
int strStr(char* haystack, char* needle) {
    char *ph, *pn;
    char *cur_hay=haystack;
    int len1=strlen(haystack);
    int len2=strlen(needle);
    while(cur_hay - haystack <= len1 - len2){
        ph = cur_hay;
        pn = needle;
        while(*ph != '\0' && *pn != '\0' && (*ph == *pn)){
            ph++;
            pn++;
        }
        if(*pn == '\0')
            return cur_hay - haystack;
        cur_hay++;
    }
    return -1;
}
/* notes:
 * If we write the while loop just as 'while(*cur_hay){...}',
 * it will be reject as *Time Limit Exceeded* on leetcode.
 */

int main(){
    char hay[] = "iloveleetcode";
    char needle1[] = "leet";
    char needle2[] = "geek";
    printf("%s, %s, %d\n", hay, needle1, strStr(hay, needle1));
    printf("%s, %s, %d\n", hay, needle2, strStr(hay, needle2));
    return 0;
}
