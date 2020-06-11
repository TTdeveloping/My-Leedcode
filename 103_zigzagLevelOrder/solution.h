#pragma once
#include <iostream>
# include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> node_val;
		queue<TreeNode*> q;
		if (root == NULL) retrun node_val;
		q.push(root);
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 1; i <= len; i++)
			{
				TreeNode *p = q.front();
				node_val.push_back(p->val)
			}
		}

	}
};