#### [面试题 04.02. 最小高度树](https://leetcode-cn.com/problems/minimum-height-tree-lcci/)

**题目：**给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
**示例:**

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 

**代码：**

```c++
//二叉搜索树的定义就是：它左子树所有的节点值都小于根结点的值，右子树所有结点值都大于根结点的值。保证高度最小：当树中的任意结点的左右子树高度差都不超过 1 时，整棵树的深度最小。如果每次选中间节点当作根结点，左右子树的高度是不超过1的。
class Solution {
public:
    TreeNode* dfs(vector<int>&nums,int L,int R){
        if(L>R) return NULL;
        int mid = (L+R)>>1;
        auto header = new TreeNode(nums[mid]);
        header->left = dfs(nums,L,mid-1);
        header->right = dfs(nums,mid+1,R);
        return header;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return dfs(nums,0,nums.size()-1);
    }
};
```

