#include <stdio.h>
#include <limits.h>
#include <ctype.h>
// 记得要处理 *溢出* 问题
int myAtoi(char* str) {
    int sign=1, i; // sign 记得要初始化
    long res=0;  // 防止发生溢出
    for(i=0; isspace(str[i]); i++)
        ;
    if(str[i] == '-'){
        sign = -1;
        i++;
    } else if(str[i] == '+'){
        sign = 1;
        i++;
    }
    for(; isdigit(str[i]); i++){
        res = res * 10 + (str[i]-'0');
        if(sign == 1 && res > INT_MAX)
            return INT_MAX;
        //else if (sign == -1 && res > -(long)INT_MIN) // 容易犯错的写法,
        //直接写 -INT_MIN 是不对的
        else if (sign == -1 && -res < INT_MIN) // 不容易犯错的写法
            return INT_MIN;
    }
    return sign * res;
}
// 注意： INT_MIN 是个 int，所以 -INT_MIN 已经发生了overflow，一定要显式的进行类型转换。

int main(){
    char *s="-1";
    printf("%d\n", myAtoi(s));
    char *s2="-123456789123";
    printf("%d\n", myAtoi(s2));
    return 0;
}
