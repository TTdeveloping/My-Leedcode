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
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2)
	{   //ListNode header 和ListNode *header .
	    //一种是传值，一种是传指针，后者在函数里改变结构体的数据后上级函数里也能得到修改后的数据
		//ListNode header = NULL;
		//ListNode *p = &header;
		ListNode *header = new ListNode(NULL);
		ListNode *p = header;
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 ==nullptr) 
		{
			return l1;
		}
		//l1 = {1,2,3,4,}
		//l2 = {1,3,5,6}
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			} 
			else 
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1 != NULL) 
		{
			p->next = l1;
		}
		if (l2 != NULL) 
		{
			p->next = l2;
		
		}
		//return header.next;
		return header->next;
	}
};