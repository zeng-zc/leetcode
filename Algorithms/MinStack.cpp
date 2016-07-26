// https://leetcode.com/problems/min-stack/
// 用两个deque 来实现，一个正常用，一个用于维护最小值
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        a.push_back(x);
        if (b.empty() || x<=b.back()) // 易错点：忘了等号。否则pop一个最小值后，第二次取最小值就是错误的
            b.push_back(x);
        else
            b.push_front(x);
    }
    
    void pop() {
        int x = a.back();
        a.pop_back();
        if (x==b.back())
            b.pop_back();
        else
            b.pop_front();
    }
    
    int top() {
        return a.back();
    }
    
    int getMin() {
        return b.back();
    }
private:
    deque<int> a;
    deque<int> b;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
