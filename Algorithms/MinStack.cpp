// https://leetcode.com/problems/min-stack/
// 用两个stack 来实现，一个正常用，一个用于维护最小值
#include <stack>
class MinStack {
public:
    void push(int x) {
        a.push(x);
        if (b.empty() || x<=b.top())
            b.push(x);
    }
    void pop() {
        int x = a.top();
        a.pop();
        if (x==b.top())
            b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
private:
    std::stack<int> a;
    std::stack<int> b;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */



// 上面的实现有个弊端：第二个stack存的是元素实体，而不是索引或者指针。当有相同的最小值入stack时，会出问题
// 改进：由于底层的std::stack 不提供迭代器，std::vector 的迭代器在插入元素后可能失效，所以使用 std::forward_list 
//       来作为底层stack的容器
class MinStack2 {
public:
    void push(int x) {
        data_stack.push_front(x);
        if (index_stack.empty() || x < getMin()) {
            index_stack.push(data_stack.begin());
        }
    }

    void pop() {
        auto it = data_stack.begin();
        if (it == index_stack.top()) { // 注意比较的是那个索引，而不是那个元素实体
            index_stack.pop();
        }
        data_stack.pop_front();
    }

    int top() {
        return data_stack.front();
    }

    int getMin() { // 由调用者保证非空
        return *index_stack.top();
    }
private:
    std::list<int> data_stack; // 由于leetcode 不支持 forword_list，所以这里用list 来实现
                               // 模拟stack
    std::stack<decltype(data_stack.begin())> index_stack;
};
// accepted
