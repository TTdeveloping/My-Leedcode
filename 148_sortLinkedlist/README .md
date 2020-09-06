#### [148. 排序链表](https://leetcode-cn.com/problems/sort-list/)

**题目：**在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

**示例 1:**

```
输入: 4->2->1->3
输出: 1->2->3->4
```

**示例 2:**

```
输入: -1->5->3->4->0
输出: -1->0->3->4->5
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

//思路：通过递归实现链表归并排序，有以下两个环节：

    分割 cut 环节： 找到当前链表中点，并从中点将链表断开（以便在下次递归 cut 时，链表片段拥有正确边界）；
        我们使用 fast,slow 快慢双指针法，奇数个节点找到中点，偶数个节点找到中心左边的节点。
        找到中点 slow 后，执行 slow.next = None 将链表切断。
        递归分割时，输入当前链表左端点 head 和中心节点 slow 的下一个节点 tmp(因为链表是从 slow 切断的)。
        cut 递归终止条件： 当head.next == None时，说明只有一个节点了，直接返回此节点。
        最后合并。
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * tmp = slow->next;
        slow->next = NULL;
        ListNode * left = sortList(head);
        ListNode * right = sortList(tmp);
        ListNode *h = new ListNode(0);
        ListNode *res = h;
        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
                 h->next = left;
                 left = left->next;
                }
            else {
                h->next = right;
                right = right->next;
            } 
            h = h->next;
        }
        h->next = left!=NULL ? left : right; 
        return res->next;
    }
};
```