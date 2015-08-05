// https://leetcode.com/problems/implement-stack-using-queues/
/*
 Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:

    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

class Stack {
public:
    queue<int> place; // 用于入列的
    queue<int> storage; // 用于腾挪
    queue<int> *ptr_place = &place, *ptr_storage = &storage;  // 很奇怪这里不能用auto
    // 用两个指针来操作两个队列
    // 算法：ptr_place 始终指向装元素的那个队列，
    // ptr_storage 始终指向用于腾挪的那个队列。
    // pop 时，将 ptr_place 中初最先入列的那个元素外，
    // 其他的元素全部腾挪到 ptr_storage 中去。
    // push 时，只需向 ptr_place 队列push就行了。

    // Push element x onto stack.
    void push(int x) {
        ptr_place->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int buf; // 从 ptr_place出列后先存在buf中，如果ptr_place还有元素，则才入列到
                    // ptr_storage 中去。
        buf = ptr_place->front();
        ptr_place->pop();
        while(!ptr_place->empty()){
            ptr_storage->push(buf);
            buf = ptr_place->front();
            ptr_place->pop();
        }
        swap(ptr_place, ptr_storage);
    }

    // Get the top element.
    int top() {
        int buf;
        buf = ptr_place->front();
        ptr_place->pop();
        while(!ptr_place->empty()){
            ptr_storage->push(buf);
            buf = ptr_place->front();
            ptr_place->pop();
        }
        ptr_storage->push(buf);
        swap(ptr_place, ptr_storage);
        return buf;
    }

    // Return whether the stack is empty.
    bool empty() {
        return ptr_place->empty() && ptr_storage->empty();
    }
};

/* notes:
 * 上面的代码中，top() 和 pop() 中有大量相同的代码，比较丑陋，
 * 下面将 buf 设为类的成员变量，改善这种情况。
 * 只是去除了重复代码，运行效率并没有改善。
 */

class Stack2 {
public:
    queue<int> place; // 用于入列的
    queue<int> storage; // 用于腾挪
    queue<int> *ptr_place = &place, *ptr_storage = &storage;  // 很奇怪这里不能用auto
    int buf;

    // Push element x onto stack.
    void push(int x) {
        ptr_place->push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        buf = ptr_place->front();
        ptr_place->pop();
        while(!ptr_place->empty()){
            ptr_storage->push(buf);
            buf = ptr_place->front();
            ptr_place->pop();
        }
        swap(ptr_place, ptr_storage);
    }

    // Get the top element.
    int top() {
        this->pop();
        this->push(buf);
        return buf;
    }

    // Return whether the stack is empty.
    bool empty() {
        return ptr_place->empty() && ptr_storage->empty();
    }
}
