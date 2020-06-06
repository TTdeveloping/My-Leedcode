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

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k)
	{
		//ListNode *p, *q;
		ListNode *p;
		p = head;
		for (int i = 0; i < k; i++)
		{
			p = p->next;
		}
		//q = p;
		while (p != NULL)
		{
			//q = q->next;
			p = p->next;
			head = head->next;
		}

		return head;

	}
};