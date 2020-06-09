#include <iostream>
#include "tree.h"
#include "linklist.h"
#include "solution.h"


int main() {
	Solution s;

	const int N = 7;
	int nums[N] = { 3,9,20,NULL,NULL,15,7 };
	TreeNode *tree;
	creatTreeNode(tree, nums, N, 0);
	//int res = s.maxDepth(tree);
	vector<vector<int>>res =  s.zigzagLevelOrder(tree);
	for (int i = 0; i <res.size(); i++)
	{
		for (int j = 0; j <res[i].size(); j++)
		{
			std::cout << res[i][j] << std::endl;
			
		}
		std::cout << "********" << std::endl;
	}
	std::cout <<  "Test Finished." << std::endl;
	std::getchar();

	return 0;
}