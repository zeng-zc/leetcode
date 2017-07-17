// 类似于 minStack
// https://leetcode.com/problems/min-stack/#/description 
// leetcode 上没有这道题

#include <queue>
#include <iterator>
#include <iostream>
#include <list>

// 用一个额外的 deque 来存索引
class MinQueue {
public:
    void push(int x) {
        data_stack.push_front(x);
        while (!index_stack.empty() && x < *index_stack.front()) {
            index_stack.pop_front();
        }
        index_stack.push_front(data_stack.begin());
    }

    void pop() {
        auto it = std::prev(data_stack.end()); // 最后那个元素对应的迭代器
        if (it == index_stack.back()) { // 注意比较的是那个索引，而不是那个元素实体
            index_stack.pop_back();
        }
        data_stack.pop_back();
    }

    int top() { // 下一个要弹出的元素
        return data_stack.back();
    }

    int getMin() { // 由调用者保证非空
        return *index_stack.back();
    }

private:
    std::list<int> data_stack; // std::list 的好处是迭代器不会失效
    std::deque<decltype(data_stack.begin())> index_stack;
    // 维护的是一系列的最小值对应的索引，最右边的是最小值，然后是第二小的值
};

int main() {
    MinQueue q;
    q.push(-2);
    q.push(-10);
    q.push(-3);
    std::cout << q.getMin() << '\n';  // --> Returns -2.
    q.pop();
    std::cout << q.top() << '\n';     // --> Returns 0.
    std::cout << q.getMin() << '\n';  // --> Returns -2.

    q.pop();
    q.push(5);
    std::cout << q.top() << '\n';     // --> Returns 0.
    std::cout << q.getMin() << '\n';  // --> Returns -2.
    return 0;
}
