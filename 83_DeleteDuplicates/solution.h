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
	ListNode *deleteDuplicates(ListNode* head)
	{
		ListNode *p = head;
		while (p != NULL && p->next != NULL)
		{
			if (p->next->val == p->val)
			{
				ListNode *q = p->next;
				p->next = q->next;
			}
			else
			{
				p = p->next;
			}
		}
		return head;
	}
		
};