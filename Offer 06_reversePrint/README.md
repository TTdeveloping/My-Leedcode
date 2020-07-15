#### [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

**题目：**输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

**示例 1：**

```
输入：head = [1,3,2]
输出：[2,3,1]
```

**限制：**

0 <= 链表长度 <= 10000

**思路：**

```
超级简单，以当前指针是否为空来终止循环，遍历链表，把每一个节点的值压入栈中，再每次从栈中取出栈顶元素放入列表中，这样就实现了倒着打印链表中的元素了。当然，也有值得反复学习的基础知识，比如，判断栈是否为空，应该是empty()这个函数。刚开始写成!s/s!=NULL。
```

**代码：**

```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int>s;
        vector<int>res;
        ListNode*p = head;
        while(p!=NULL){
            s.push(p->val);
            p=p->next;
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;

    }
};
```

