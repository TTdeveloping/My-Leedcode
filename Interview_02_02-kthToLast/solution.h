#pragma once
#include <iostream>
//#include <cstdlib>
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
#include <vector>
using std::vector;
#include <bitset>
#include <array>
using std::array;
#include <unordered_set>
#include <stack>
using std::stack;
using std::swap;

/**
	No 21：合并两个有序链表
**/

class Solution 
{
public:
	int kthToLast(ListNode* head, int k)
	{
		if (head == NULL) return NULL;
		ListNode *p = head;
		ListNode *q = head;
		int count = 1;
		while (p->next != NULL)
		{
			count += 1;
			p = p->next;

		}
		while (k != count)
		{
			q = q->next;
			count--;
		}
		return q->val;

	}
		
};