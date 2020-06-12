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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> r;
		stack<TreeNode*> s;
		s.push(root);
		if (!root) return r;
		while (!s.empty()) {
			TreeNode *p = s.top();
			s.pop();
			r.push_back(p->val);
			if (p->left != NULL) s.push(p->left);
			if (p->right != NULL) s.push(p->right);
		}

		reverse(r.begin(), r.end());
		return r;

	}

};