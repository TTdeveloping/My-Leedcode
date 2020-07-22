#### [95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

**题目：**给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

**示例：**

```
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

提示：

    0 <= n <= 8

**代码：**

```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode *>{};
        else return generateTrees(1,n);
        
    }
     vector<TreeNode*> generateTrees(int left, int right){
         vector<TreeNode*>res;
        if(left>right) {
            res.push_back(nullptr);
            return res;
        }
        else{
            for(int i=left;i<=right;i++){
                vector<TreeNode*>leftTrees=generateTrees(left, i-1);
                vector<TreeNode*>rightTrees=generateTrees(i+1,right);
                for(TreeNode*left:leftTrees){
                    for(TreeNode*right:rightTrees){
                        TreeNode*t=new TreeNode(i);
                        t->left=left;
                        t->right=right;
                        res.push_back(t);
                    }
                }
            }
            return res;     
        }
    }
};
```

