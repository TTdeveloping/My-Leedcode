#### [112. 路径总和](https://leetcode-cn.com/problems/path-sum/)

**题目：**给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

**说明:** 叶子节点是指没有子节点的节点。

**示例:** 
给定如下二叉树，以及目标和 sum = 22，

```
          5
         / \
        4   8
       /   / \
      11  13  4
     /  \      \
    7    2      1
```

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

**代码：**

```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        queue<TreeNode *>node;
        queue<int>val;
        node.push(root);
        val.push(root->val);
        while(!node.empty()){
            TreeNode*now = node.front();
            int temp = val.front();
            node.pop();
            val.pop();
            if(now->left!=NULL) {
                node.push(now->left);
                val.push(now->left->val + temp);
            }
            if(now->right!=NULL)  {
                node.push(now->right);
                val.push(now->right->val + temp);
            }
            if(now->left==NULL && now->right==NULL){
                if(temp==sum) return true;
                else continue;
            }
        }
        return false;     
    }
};
```