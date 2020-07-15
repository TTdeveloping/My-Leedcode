#### [剑指 Offer 28. 对称的二叉树](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/)

**题目：**请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。(本题和101题对称二叉树相同)

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

        1
       / \
      2   2
     / \ / \
    3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

        1
       / \
      2   2
       \   \
       3    3 
**示例 1：**

```
输入：root = [1,2,2,3,4,4,3]
输出：true
```

**示例 2：**

```
输入：root = [1,2,2,null,3,null,3]
输出：false
```

**限制：**

0 <= 节点个数 <= 1000

**代码：**

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL?true:recur(root->left, root->right);
    }
    bool recur(TreeNode*L, TreeNode*R){
        if(L==NULL && R==NULL) return true;
        if(L==NULL || R==NULL ||L->val!=R->val) return false;
        return recur(L->left,R->right)&&recur(L->right, R->left);
    }
};
```

