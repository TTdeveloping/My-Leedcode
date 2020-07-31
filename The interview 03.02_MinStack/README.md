#### [面试题 03.02. 栈的最小值](https://leetcode-cn.com/problems/min-stack-lcci/)

**题目：**请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。

**示例：**

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

**代码：**

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s1;
    stack<int>s2;
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }
        else{  //最精妙的就是每压入一个元素，s2也会对应压入包含这个元素在内所有值的的最小值。
            if(x<s2.top()){
                s2.push(x);
            }
            else{
                s2.push(s2.top());
            }
        }

    }
    
    void pop() {
        s1.pop();
        s2.pop();

    }
    
    int top() {
        return s1.top();

    }
    
    int getMin() {
        return s2.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

