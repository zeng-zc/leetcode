// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  
        for(int i = 0; i < s.size(); i++)  {  
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){  
                st.push(s[i]);  
            }  
            if(s[i] == ')')  {  
                if(st.empty() || st.top() != '(')  
                   return false;  
                st.pop();  
            }  
            if(s[i] == '}')  {  
                if(st.empty() || st.top() != '{')  
                   return false;  
                st.pop();  
            }  
            if(s[i] == ']')  {  
                if(st.empty() || st.top() != '[')  
                   return false;  
                st.pop();  
            }              
        }  
        if(st.empty() == 0)  
           return false;  
        return true;  
    }  
}; 

/*
 * notes:
 * 注意 stack 的pop 函数返回的是 void 类型，只是删除了最后一个元素，
 * 但不返回这个元素，这是容易犯错的（compile error).
 */

