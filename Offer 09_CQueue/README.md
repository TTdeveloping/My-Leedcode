#### [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

**题目：**用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

**示例 1：**

```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```

**示例 2：**

```
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

**提示：**

```
1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
```

**思路：**

很多人没有看懂示例中输入输出的意思，我来解释一下：**["CQueue","appendTail","deleteHead","deleteHead"]** 这一个列表中存放的是调用的函数，**[[],[3],[],[]]**是可以理解为对应函数的输入的参数值。输出：**[null,null,3,-1]**表示的就是执行完每个函数后的结果。第一个null意思也提示我们CQueue这个函数是没有返回值的，搜易为null；第二个null是执行appendTail函数，往队尾插入元素，没有返回值，所以为null；3是在执行deleteHead函数，它由返回值，返回队首元素。-1是因为再次执行deleteHead函数的时候，队列中已经没有了元素，返回-1。 具体见代码实现。**注意：**用栈实现队列，栈底的元素就是队列的队首元素。因为队列先进先出的原则，要想把队首元素删除，只靠一个栈完成不了，因为队首元素被压入栈底，不能被直接删除。只能借助第二个栈。我们定义两个栈s1和s2，s1用来操作在队尾插入元素（因为栈底是队尾，每次压入栈中元素，就是相当于再队尾插入元素）；用s2来删除队首元素，如果s2为空且s1为空的话，返回-1，如果s2为空，s1不为空，就将s1中的元素全部弹出压入s2中，此时，队首元素在栈顶，可以直接删除并返回。

**代码：**

```
class CQueue {
    stack<int> s1,s2;
public:
    CQueue() {
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
      if(s2.empty() && s1.empty()) return -1;
      if(s2.empty()){
          while(!s1.empty()){
              s2.push(s1.top());
              s1.pop();
          }
      }

      int topnum = s2.top();
      s2.pop();
      return topnum;

    }
       
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

