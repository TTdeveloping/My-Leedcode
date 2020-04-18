#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	vector<int> nums = { 1, 2, 3, 4 };
	ListNode * l1 = creatLinkedList(nums.begin(), nums.end());

	vector<int> nums2 = { 1, 3, 5, 6 };
	ListNode * l2 = creatLinkedList(nums2.begin(), nums2.end());
	
	ListNode * res = s.mergeTwoLists(l1, l2);

	std::cout << "" << std::endl;

	std::cout << std::endl <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
} 