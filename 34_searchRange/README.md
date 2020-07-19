#### [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

**题目：**给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

**示例 1:**

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
```

**示例 2:**

```
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
```

**代码：**

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.size() < 1) return res;
        // 第一次二分查找，找到左边界
        int l = 0, r = nums.size();
        while(l < r){
            int m = ( l + r ) / 2;
            nums[m] < target ?l = m + 1 : r = m;
        }
        if(l == nums.size()) return res; 
        if( target == nums[l]) res[0] = l;
        else return res;
        // 第二次二分查找，找到右边界
        r = nums.size();
        while(l < r){
            int m = ( l + r ) / 2;
            target < nums[m] ? r = m : l = m + 1;
        }
        res[1] = l - 1;
        return res;
    }
};
```

