// https://leetcode.com/problems/add-digits/
/*
 Given a non-negative integer num, repeatedly add all its digits until the
result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime? 
*/

// Three solutions. The perfect one is at the bottom.

// naiive version
int addDigits(int num) {
    if(num / 10 == 0){
        return num;
    }
    int sum=0;
    while(num != 0){
        sum += num%10;
        num /= 10;
    }
    return addDigits(sum);
}

// loop 
int addDigits(int num) {
    while(1){
        int sum=0;
        while(num != 0){
            sum += num%10;
            num /= 10;
        }
        if(sum / 10 == 0)
            return sum;
        else
            num = sum;
    }
}

// perfect solution
// The results would be in 1..9, only nine values, does it relates to %9?
int addDigits(int num) {
    if(num==0)
        return 0;
    if(num % 9 ==0)  // for example 45, return 9
        return 9;
    return num%9;
}

