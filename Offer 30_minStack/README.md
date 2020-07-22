#### [剑指 Offer 30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

**题目：**定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。 (和[155. 最小栈](https://leetcode-cn.com/problems/min-stack/)相同)

**示例:**

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```

**提示：**

    各函数的调用总次数不超过 20000 次

**代码：**

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>A;
    stack<int>B;
    MinStack() {
    }
    
    void push(int x) {
        A.push(x);
        if(B.empty()||x<=B.top()) B.push(x);
    }
    
    void pop() {
        if(!A.empty()){
             if(B.top()==A.top()) B.pop();
        }
        A.pop();
    }
    
    int top() {
        return A.top();
    }
    
    int min() {
        return B.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```
