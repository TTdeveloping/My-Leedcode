#### [面试题 04.05. 合法二叉搜索树](https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/)

**题目：**实现一个函数，检查一棵二叉树是否为二叉搜索树。
        **示例 1:**

```
输入:
    2
   / \
  1   3
输出: true
```

**示例 2:**

```
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
```

**思路：**

保证左子树的最大值小于根结点的值，右子树的最小值大于根结点的值。而且需要注意的是：空树或者只有一个根结点的都是二叉搜索树。根结点的左右子树也要是二叉搜索树。

**代码：**

```
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		if (root->left == NULL && root->right == NULL) return true;
		if (root->left != NULL) {
			int leftMax = getMax(root->left);
			if (leftMax >= root->val) return false;
		}
		if (root->right != NULL) {
			int rightMin = getMin(root->right);
			if (rightMin <= root->val) return false;
		}
		return isValidBST(root->left) && isValidBST(root->right);

	}
	int getMax(TreeNode * root) {
		if (root->right == NULL) return root->val;
		else return getMax(root->right);
	}
	int getMin(TreeNode * root) {
		if (root->left == NULL) return root->val;
		else return getMin(root->left);
	}
};
```

