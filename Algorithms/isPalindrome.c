/* https://leetcode.com/problems/valid-palindrome/
 Given a string, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. 
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
typedef enum{false, true} bool;
bool isPalindrome(char* s) {
    if(*s == '\0')
        return 1;
    int len=strlen(s);
    for(int i=0, j=len-1; i<j; i++, j--){
        while(i<len && !isalnum(s[i]))
            i++;
        while(j>=0 && !isalnum(s[j]))
            j--;
        if(tolower(s[i]) != tolower(s[j]))
            return 0;
    }
    return 1;
}

/* notes:
 * easy errors:
 * In the two while loops, forget to include 'i<len'. It can 
 * cause segfault for "..," input.
 * Before indexing a subsripe of an array, we __should check__ whether
 *     it's in bound.
 */

int main(){
    char *s1="A man, a plan, a canal: Panama";
    char *s2="race a car";
    char *s3="";
    char *s4=".:";
    printf("%s: %d\n", s1, isPalindrome(s1));
    printf("%s: %d\n", s2, isPalindrome(s2));
    printf("%s: %d\n", s3, isPalindrome(s3));
    printf("%s: %d\n", s4, isPalindrome(s4));
    return 0;
}
