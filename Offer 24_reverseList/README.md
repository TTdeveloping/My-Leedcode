#### [剑指 Offer 24. 反转链表](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/)

**题目：**定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

**示例:**

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

**限制：**

0 <= 节点个数 <= 5000

**代码1：**

```c++
//借助栈。因为栈是先进后出，所以可以实现链表的翻转。
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//if (head == NULL) return NULL;
		stack< ListNode * > s;
		while (head != NULL) {
			s.push(head);
			head = head->next;
		}
		if (s.empty()) return NULL;
		ListNode *rev = s.top();
		s.pop();
		ListNode *p = rev;
		while (!s.empty()) {
			ListNode *cur = s.top();
			s.pop();
			p->next = cur;
			p = p->next;
		}
		p->next = NULL;
		return rev;
	}
};
int main() {
	Solution s; 
	vector<int>nums = {1,2,3,4};
	ListNode * l = creatLinkedList(nums.begin(), nums.end());
	auto res = s.reverseList(l);
	ListNode * p = res;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	std::cout <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
}
```

**代码2：**

```c++
//利用双指针。
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode * pre = NULL;
		ListNode * cur = head;
		while (cur != NULL) {
			ListNode *tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};
int main() {
	Solution s; 
	vector<int>nums = {1,2,3,4};
	ListNode * l = creatLinkedList(nums.begin(), nums.end());
	auto res = s.reverseList(l);
	ListNode * p = res;
	while (p != NULL) {
		cout << p->val << endl;
		p = p->next;
	}
	std::cout <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
}
```

