#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	const int N = 4;
	int nums[4] = { 1,NULL,2,3 };
	//int nums[4] = { 1,4,3,2 };
	TreeNode *tree;
	creatTreeNode(tree, nums, N, 0);
	//int res = s.maxDepth(tree);
	vector<int>res =  s.postorderTraversal(tree);
	for (int i = 0; i <res.size(); i++)
	{
		
		std::cout << res[i] << std::endl;
	}
	std::cout <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
}