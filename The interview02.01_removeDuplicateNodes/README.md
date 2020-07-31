#### [面试题 02.01. 移除重复节点](https://leetcode-cn.com/problems/remove-duplicate-node-lcci/)

**题目：**编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

**示例1:**

```
 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
```

**示例2:**

```
 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
```

**提示：**

    链表长度在[0, 20000]范围内。
    链表元素在[0, 20000]范围内。

**进阶：**

```
如果不得使用临时缓冲区，该怎么解决？
```

**代码：**

```c++
//考虑“进阶”中说明不使用临时缓冲区的做法。用双重循环。
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode *p = head;
        while(p!=NULL){
            ListNode *q = p;
            while(q->next!=NULL){
                if(q->next->val==p->val) q->next=q->next->next;
                else q=q->next;
            }
            p=p->next;
        }
        return head;
    }
};
```

