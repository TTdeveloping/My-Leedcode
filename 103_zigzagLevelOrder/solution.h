#pragma once
#include <iostream>
# include <queue>

using namespace std;

class Solution
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		queue<TreeNode *> q;
		if (root == NULL) return res;
		q.push(root);
		int levl = 1;
		while (!q.empty())
		{
			int tep_size = q.size();
			vector<int> temp;
			for (int i = 1; i <= tep_size; i++)
			{
				TreeNode *p = q.front();
				q.pop();
				temp.push_back(p->val);
				if (p->left != NULL) q.push(p->left);
				if (p->right != NULL) q.push(p->right);

			}
			if (levl % 2 == 0)
			{
				reverse(temp.begin(), temp.end());
			}
			res.push_back(temp);
			levl++;

		}
		return res;
	}
};