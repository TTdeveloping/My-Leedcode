#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	vector<int> nums = { 1, 2, 3, 4, 5 };
	int k = 3;
	ListNode * l = creatLinkedList(nums.begin(), nums.end());
	
	int res = s.kthToLast(l,k);

	std::cout << "" << std::endl;

	std::cout << std::endl <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
} 