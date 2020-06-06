#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	vector<int> nums = { 1, 2, 3, 4, 5 };
	int k = 2;
	ListNode * l = creatLinkedList(nums.begin(), nums.end());
	ListNode * res = s.getKthFromEnd(l,k);
	while (res!= NULL)
	{
		std::cout << res->val << std::endl;
		res = res->next;
	}

	std::cout << "" << std::endl;

	std::cout << std::endl <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
} 