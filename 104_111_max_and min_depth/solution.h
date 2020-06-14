#pragma once
#include <iostream>
# include <queue>
#include <unordered_map>

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
class Solution1 {
public:
	int maxDepth(TreeNode* root) {
		int count = 0;
		queue<TreeNode*> q;
		if (!root) return 0;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			for (int i = 1; i <= len; i++) {
				TreeNode *p = q.front();
				q.pop();
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
			count++;

		}
		return count;


	}
};
class Solution {
public:
	int minDepth(TreeNode* root) {
		int count = 0;
		queue<TreeNode*> q;
		if (!root) return 0;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			count++;
			for (int i = 1; i <= len; i++) {
				TreeNode *p = q.front();
				q.pop();
				if ((p->left == NULL) && (p->right==NULL)) {
					return count;
				}
				if (p->left != NULL) q.push(p->left);
				if (p->right != NULL) q.push(p->right);
			}
		}
		return count;
	}
};