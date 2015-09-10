// https://leetcode.com/problems/excel-sheet-column-title/
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

// 跟上一道题相反。十进制转化为26进制
#include <stdio.h>
#include <stdlib.h>
char* convertToTitle(int n){
    char *buf = (char *)malloc(sizeof(char) *256);
    buf[255]='\0';
    int pos=254, r;
    while(n != 0 && pos >=0){
        r=n%26;
        if(r == 0){
            buf[pos--] = 'Z';
            n--;
        }
        else
            buf[pos--] = r + ('A'-1);
        n = n/26;
    }
    if(n!=0){
        printf("Too large!");
        return NULL;
    }
    return buf+pos+1;
}
   
int main(){
    printf("%s\n", convertToTitle(28));
    printf("%s\n", convertToTitle(26));
    printf("%s\n", convertToTitle(25));
    printf("%s\n", convertToTitle(2));
    return 0;
}


