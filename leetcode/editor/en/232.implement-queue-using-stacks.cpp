#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Implement the following operations of a queue using stacks. 
//
// 
// push(x) -- Push element x to the back of queue. 
// pop() -- Removes the element from in front of queue. 
// peek() -- Get the front element. 
// empty() -- Return whether the queue is empty. 
// 
//
// Example: 
//
// 
//MyQueue queue = new MyQueue();
//
//queue.push(1);
//queue.push(2);  
//queue.peek();  // returns 1
//queue.pop();   // returns 1
//queue.empty(); // returns false 
//
// Notes: 
//
// 
// You must use only standard operations of a stack -- which means only push to 
//top, peek/pop from top, size, and is empty operations are valid. 
// Depending on your language, stack may not be supported natively. You may simu
//late a stack by using a list or deque (double-ended queue), as long as you use o
//nly standard operations of a stack. 
// You may assume that all operations are valid (for example, no pop or peek ope
//rations will be called on an empty queue). 
// 
// Related Topics Stack Design


//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
    stack<int> stk;

public:
    /** Initialize your data structure here. */
    MyQueue() : stk() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        auto tmp = stack<int>();
        while (!stk.empty()) {
            tmp.push(stk.top()); stk.pop();
        }
        stk.push(x);
        while (!tmp.empty()) {
            stk.push(tmp.top()); tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto const x = stk.top(); stk.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestImplementQueueUsingStacks, testcase) {
    auto que = MyQueue();
    que.push(1);
    que.push(2);
    ASSERT_EQ(que.peek(), 1);
    ASSERT_EQ(que.pop(), 1);
    ASSERT_EQ(que.peek(), 2);
    ASSERT_EQ(que.empty(), false);
}
