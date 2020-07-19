#### [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/)

**题目：**统计一个数字在排序数组中出现的次数。

**示例 1:**

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
```

**示例 2:**

```
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
```

限制：

0 <= 数组长度 <= 50000

**代码：**

```c++
class Solution {
    int binary(vector<int>& nums, int target) {  // 二分查找target最后一个位置
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        // if(r < 0 || nums[r] != target) return -1;
        return r;
    }
public:
    int search(vector<int>& nums, int target) {
        return binary(nums, target) - binary(nums, target - 1);
    }
};
```

