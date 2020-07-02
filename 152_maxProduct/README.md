#### [152. 乘积最大子数组](https://leetcode-cn.com/problems/maximum-product-subarray/)（经典）

**题目：**给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

**示例 1:**

```
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```

**示例 2:**

```
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
```

**思路：**

这道题和上边的53道题还是不一样的，因为可能会有负负得正出现。我们遍历数组（从第二个数开始），我们定义两个数组，一个是x用来存储以nums[i]结尾的子数组的最大乘积，另一个用n来存储以nums[i]结尾的子数组的最小乘积。如果nums[i]>0的话，则最大乘积应该在nums[i]和nums[i] * x[i-1]中找；最小乘积应该在nums[i]和nums[i] * n[i-1]。如果nums[i]<0的话，则最大乘积应该在nums[i]和nums[i] * n[i-1]中找；最小乘积应该在nums[i]和nums[i] * x[i-1]找。题意是找到最大乘积，最后只需要再遍历数组x找到最大值即可。

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len =  nums.size();
        vector<int> x(len,0),n(len,0);
        x[0] = nums[0];
        n[0] = nums[0];
        for(int i=1;i<len;i++){
            if(nums[i]>=0){
                n[i]=min(nums[i],nums[i]*n[i-1]);
                x[i]=max(nums[i],nums[i]*x[i-1]);
            }
            if(nums[i]<0){
                n[i]=min(nums[i],nums[i]*x[i-1]);
                x[i]=max(nums[i],nums[i]*n[i-1]);
            }
        }
        int max_val = x[0];
        for(int i=1;i<len;i++){
            if(x[i]>max_val) max_val = x[i];
        }
        return max_val;
    }
};
```

**优化进阶：**

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len =  nums.size();
        int res = nums[0];
        int preMin = nums[0],curMin;
        int preMax = nums[0],curMax;
        for(int i=1;i<len;i++){
            if(nums[i]>=0){
                curMax = max(preMax*nums[i],nums[i]);
                curMin = min(preMin*nums[i],nums[i]);
            }
            else{ 
                curMax = max(preMin*nums[i],nums[i]);
                curMin = min(preMax*nums[i],nums[i]);
            }

            res = max(curMax,res);

            preMax = curMax;
            preMin = curMin;
        }
        return res;     
    }
};
```