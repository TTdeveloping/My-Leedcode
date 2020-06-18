#### [面试题27. 二叉树的镜像](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

镜像输出：

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

**示例 1：**

```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**解题思路1：**（迭代遍历每一个节点进行左右交换）

```
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (!root) return root;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *p = q.front();
			q.pop();
			if (p->left) q.push(p->left);
			if (p->right) q.push(p->right);
			TreeNode *temp = p->left;
			p->left = p->right;
			p->right = temp;
		}
		return root;

	}
};
```

**解题思路2：**（递归思想）

```
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (!root) return root;
		TreeNode * temp= root->left;
		root->left = root->right;
		root->right = temp;
		mirrorTree(root->left);
		mirrorTree(root->right);
		return root;
	}
};
```

此题二叉树的镜像和Leedcode上226题二叉树的翻转相同。