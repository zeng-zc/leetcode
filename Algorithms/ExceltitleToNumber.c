// https://leetcode.com/problems/excel-sheet-column-number/
/*Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

// 实际上是 26 进制转化成十进制
// 但是要注意一点：A 转化为1 而不是0.

#include <string.h>
#include <stdio.h>
int titleToNumber(char* s) {
    int res=0, len;
    len = strlen(s);
    for(int i=0; i<len; i++)
        res = res * 26 + (s[i]-'A'+1);
    return res;
}

int main(){
    printf("%d\n", titleToNumber("AB"));
    printf("%d\n", titleToNumber("Z"));
}
