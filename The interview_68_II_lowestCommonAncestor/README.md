#### [面试题68 - II. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

**题目：**给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

**示例 1:**

```
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
```

**示例 2:**

```
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。 
```

**说明:**

    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉树中。

**思路：**

如果是空树的话，则结果返回空。

**非空树时且p或者q一个在根结点上：**

- 如果根结点就是p结点，那么q结点无论是在根结点的左子树还是右子树中（说明中已经提示，p,q均存在且不同），则他俩的公共祖先就是P。

- 如果根结点就是q，那么P结点无论是在根结点的左子树还是右子树中（说明中已经提示，p,q均存在且不同），则他俩的公共祖先就是q。

**非空树时且p和q分别在根结点的不同侧：**在p和q的公共祖先就是根结点。

**非空树时且p和q分别在根结点的同侧**：那就返回一侧的值。

所以我们使用递归算法。代码如下：

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root==p ||root==q) return root;
        TreeNode*left = lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);
        if (left==NULL) return right;
        if (right==NULL) return left;
        return root;
        
    }
};
```

本题目与Leedcode的 236 题相同。