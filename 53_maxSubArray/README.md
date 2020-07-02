#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)（经典）

**题目：**给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**示例:**

```
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

**进阶:**

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

**思路：**

**思路一：**遍历数组（从第二个数开始），如果这个数前面的数是负数的话，那么这个位置的这个数就保持不变，如果它前边的数是正数的话，那要把它前边的数加到现在遍历到的这个位置的数上。原因就是，前边是负数的话，加上那个数会变得更小，所以要保持不变，前边的数是正数，加上一个正数的话，会比自己的值要大（这就符合题的目的，要找和最大的连续子数组），遍历完整个数组且计算完成后，数组中存放的数值相比原来数组中的值尽可能大。然后，可以再次遍历数组，从这些尽可能大的数值中找到最大值就是最终要得结果了。代码如下：

```
//解法一：
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        for(int i=1;i<len;i++){
            if(nums[i-1]<0) continue;
            else nums[i] = nums[i]+nums[i-1];
        }
        return *max_element(nums.begin(),nums.end());
    }
};
```

从代码中可以看出，其实我们相当于是遍历了两次数组，第一次是计算所有尽可能大的数并更新对应位置的数值，第二次我们从尽可能大的数中找最大值，又要遍历数组。

**思路二：**我们不再做最后的比较，我们直接在每一步都保存着最大值，最终只返回pre就行了，具体见代码

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = int (nums.size());
        int dp = nums[0];
        int pre = dp;
        for(int i = 1;i<size;i++)
        {
            dp = max(dp+nums[i],nums[i]);
            pre = max(pre,dp);
        }
        return pre;
    }
};
```