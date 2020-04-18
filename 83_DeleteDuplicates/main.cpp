#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	vector<int> nums = { 1, 1, 2, 3, 3 };
	ListNode * l = creatLinkedList(nums.begin(), nums.end());
	
	ListNode * res = s.deleteDuplicates(l);

	std::cout << "" << std::endl;

	std::cout << std::endl <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
} 