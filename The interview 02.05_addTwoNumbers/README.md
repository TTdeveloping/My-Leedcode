#### [面试题 02.05. 链表求和](https://leetcode-cn.com/problems/sum-lists-lcci/)

**题目：**给定两个用链表表示的整数，每个节点包含一个数位。这些数位是反向存放的，也就是个位排在链表首部。编写函数对这两个整数求和，并用链表形式返回结果。

**示例：**

```
输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
```

**进阶：**假设这些数位是正向存放的，请再做一遍。

**示例：**

```
输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912
```

**代码：**

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL) return l1==NULL?l1:l2;
        ListNode *header = new ListNode(NULL);
        ListNode *p = header;
        int z=0;
        while(l1 && l2){
            p->next = new ListNode((l1->val + l2->val+z)%10);
            z=(l1->val + l2->val+z)/10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum=l1->val+z;
            p->next=new ListNode(sum%10);
            z=sum/10;
            p=p->next;
            l1=l1->next;
        }
        while(l2){
            int sum = l2->val+z;
            p->next = new ListNode(sum%10);
            z=sum/10;
            p=p->next;
            l2=l2->next;
        }
        if(z!=0) p->next=new ListNode(z);
        return header->next;
    }
};
```

