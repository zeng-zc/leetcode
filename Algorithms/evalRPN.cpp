// https://leetcode.com/problems/evaluate-reverse-polish-notation/
/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

// 典型的 stack 的应用。
// TCPL 教材的经典题。

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ss;
        for(auto c: tokens){
            try{
                auto tmp = stoi(c);
                ss.push(tmp);
            } catch (invalid_argument&){
                auto num1 = ss.top();
                ss.pop();
                auto num2 = ss.top();
                ss.pop();
                switch(c[0]){
                    case '+':
                        ss.push(num1+num2);
                        break;
                    case '-':
                        ss.push(num2-num1);
                        break;
                    case '*':
                        ss.push(num1*num2);
                        break;
                    case '/':
                        ss.push(num2/num1);
                        break;
                }
            }
        }
        return ss.top();
    }
};

int main(){
    Solution s;
    vector<string> vs={"4", "13", "5", "/", "+"};
    cout << s.evalRPN(vs) << endl;
    vs={"2", "1", "+", "3", "*"};
    cout << s.evalRPN(vs) << endl;
    vs = {"-1","1","*","-1","+"};
    cout << s.evalRPN(vs) << endl;
    return 0;
}

/* notes:
 * 这道题的难点不在算法部分，而是字符串处理。
 * 如果用 isdigit 这样的函数来判断是否为数字，只能一位一位的处理。
 * 如果用 ctype.h 中的 atoi 来转化，它处理不了异常。
 * 当然，也可以用 strtol 来转化，但是它遇到无效字符串会返回 0.
 *
 * 另外一个容易犯错的小细节是：遇到除法时，是 num2 / num1，
 * 一不小心就会把顺序搞反。
 *
 * 还有一个容易犯错的地方是：
 * 在 switch 语句中，是将 c[0] 与 '+' 这些 char 型变量来做比较，
 * 不是用 c 直接去比较，因为 c 为 string 类型。
 */
