#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// LinkList Struct
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}//初始化当前结点值为x,指针为空
};
  
// creat LinkList by vector array
//using 别名=包括详细命名空间信息的具体的类型。
using vecIter = vector<int>::iterator;//具有int元素的迭代器类型

ListNode *creatLinkedList(vecIter begin, vecIter end) 
{
	ListNode* head = NULL;//初始化一个空指针。
	head = (begin == end) ? NULL : new ListNode(NULL);//三目运算。
	for (ListNode* cur = head; begin != end; cur = cur->next) 
	{
		cur->next = new ListNode(*begin++);
	}
	return head->next;
}