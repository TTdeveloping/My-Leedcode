#pragma once
#include <iostream>
# include <queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector <vector <int>> ret;
		if (root== NULL) return ret;

		queue <TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int currentLevelSize = q.size();
			//ret.push_back(vector <int> ());
			vector<int> tmpLevel;
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				//ret.back().push_back(node->val);
				tmpLevel.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			ret.push_back(tmpLevel);
		}

		return ret;
	}
};
