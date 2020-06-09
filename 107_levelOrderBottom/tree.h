#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void creatTreeNode(TreeNode * &tree, int nums[], int len, int index) {
	if (index >= len) return;
	tree = new TreeNode(nums[index]);
	creatTreeNode(tree->left, nums, len, 2 * index + 1);
	creatTreeNode(tree->right, nums, len, 2 * index + 2);
}

void preOrder(TreeNode *tree) {
	if (tree) {
		std::cout << tree->val << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(TreeNode *tree) {
	if (tree) {
		inOrder(tree->left);
		std::cout << tree->val << " ";
		inOrder(tree->right);
	}
}

void posOrder(TreeNode *tree) {
	if (tree) {
		posOrder(tree->left);
		posOrder(tree->right);
		std::cout << tree->val << " ";
	}
}
/**
	print by level order 
**/
void levelOrder(TreeNode *tree) 
{
	if (!tree) return;
	std::deque<TreeNode *> dequeNode;
	dequeNode.push_back(tree);
	while (dequeNode.size()) 
	{
		TreeNode *p = dequeNode.front();
		std::cout << p->val << " ";
		dequeNode.pop_front();
		if (p->left) 
		{
			dequeNode.push_back(p->left);
		}
		if (p->right) 
		{
			dequeNode.push_back(p->right);
		}
	}
}