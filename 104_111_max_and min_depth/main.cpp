#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	const int N = 7;
	int nums[N] = { 3,9,20,NULL, NULL,15,7};
	//int nums[4] = { 1,4,3,2 };
	TreeNode *tree;
	creatTreeNode(tree, nums, N, 0);
	//int res = s.maxDepth(tree);
	int res =  s.minDepth(tree);
	
	std::cout << res << std::endl;
	
	std::cout <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
}