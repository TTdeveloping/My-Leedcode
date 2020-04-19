#### [面试题 02.02. 返回倒数第 k 个节点](https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/)

实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

**示例：**

输入： 1->2->3->4->5 和 k = 2
       输出： 4

**说明：**

给定的 k 保证是有效的。

##  **解题思路：**

定义两个结点p和q都指向head，用p先遍历列表，记录列表的长度记为count（结点个数），q从头开始遍历，去搜查倒数第k个点。需要找到k和count的规律。

## 结果：

执行用时：4ms

内存消耗：10.5MB

![1587269170138](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\1587269170138.png)



## 后期优化（看过大佬的代码理解）：

**优化思路：**定义p指针开始指向head指向的地方，让p指针先走k步后“停下来”，然后再让head指针和原先“停下来”的P指针同时出发，当p指针最后走到NULL的时候“停下来”，head指针也“停下来”。因为P指针先开始比head多走了k步，p最后遍历完整个列表停下,head也停下，正好停到倒数第k个结点。返回head的val域，就是最终要的结果。

![1587270863350](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\1587270863350.png)

```c++
class Solution {
public:
    int kthToLast(ListNode* head, int k) 
    {
     ListNode* p = head;
        for(int i = 0; i < k; i++)
        {
            p = p->next;
        }
        
        while(p)
        {
            p = p->next;
            head = head->next;
        }
        
        return head->val;
    }
};
```

