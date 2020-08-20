#### [199. 二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/)

**题目：**给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

**示例:**

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
**解释:**

```
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```

**代码：**

```c++
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        deque<TreeNode*> node;
        node.push_back(root);
        while(!node.empty()){
            int len = node.size();
            TreeNode *cur = node.back();
            res.push_back(cur->val);
            for(int i=0;i<len;i++){
                TreeNode *now = node.front();
                node.pop_front();
                if(now->left) node.push_back(now->left);
                if(now->right) node.push_back(now->right);     
            }
        }
        return res;
    }
};
```

