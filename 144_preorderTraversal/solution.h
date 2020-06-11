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
		
		vector<int> output;
		if (!root) return output;
		vector<TreeNode*> node;
		node.push_back(root);
		while (!node.empty())
		{
			TreeNode *p = node.back();
			node.pop_back();
			output.push_back(p->val);
			if (p->right) node.push_back(p->right);
			if (p->left) node.push_back(p->left);
		}
		return output;
	}
};

//第二种写法
/*class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> output;
		if (!root) return output;
		stack<TreeNode*> s;
		s.push(root);

		while (!s.empty())
		{
			TreeNode *p = s.top();
			s.pop();
			output.push_back(p->val);
			if (p->right) s.push(p->right);
			if (p->left) s.push(p->left);
		}
		return output;
	}
};
*/