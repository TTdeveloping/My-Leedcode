#### [238. 除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)

**题目：**给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

**示例:**

输入: [1,2,3,4]
       输出: [24,12,8,6]

 

**提示：**题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

**说明:** 请不要使用除法，且在 O(n) 时间复杂度内完成此题。





**思路总结：**

题目的意思就是给定一个数组nums,最终输出的也是一个数组Output，但是对于Output数组的每一个元素Output[i]满足的条件是：等于给数组nums中除了索引i对应的数值之外其余各元素的积。很显然，两个数组的长度是相等的。

我们先求在nums数组中，i索引左边各数值的乘积，然后再继续乘上索引右边各数值的乘积。left表示i索引左边数值的乘积，因为数组最左边的数值没有左边的数，所以，初始left=1；right表示索引右边数值的乘积。因为数组最右边的数值没有右边的数，所以，初始right=1。左右夹击求Output数组中各元素。

```c++
#include <iostream>
# include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> productExceptSelf(vector<int>& nums) 
	{
		int n = nums.size();
		int left = 1;
	    vector<int> Output(n);
		for (int i = 0; i < n; i++)
		{
			Output[i] = left;# 第一个元素没有左边元素，所以左边乘积left赋值为1
			left = left * nums[i];
		}
		int right = 1;
		for (int i = n - 1; i >= 0; i--)# 索引左边计算完，再从右边开始夹击。
		{
			Output[i] *= right; # 因为数组最后面的数值没有右边乘积，所以right初始为1
			right *= nums[i];
		}
		return Output;

	}

};
```

