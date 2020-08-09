#### [面试题 03.04. 化栈为队](https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/)

**题目：**实现一个MyQueue类，该类用两个栈来实现一个队列。

**示例：**

```
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
```

**说明：**

    你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size 和 is empty 操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
    假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

**代码：**

```c++
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1,s2;
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = peek();
        s2.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                int val = s1.top();
                s2.push(val);
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
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
```

