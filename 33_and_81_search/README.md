#### [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)（不包含重复元素）

**题目：**假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

**示例 1:**

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```

**示例 2:**

```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

**代码：**

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        if(n==1) return nums[0] == target? 0:-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            if(nums[0]<nums[mid]){
                if(target>=nums[0] && target<nums[mid]) r = mid-1;
                else l = mid+1;
            }
            else{
                if(target>nums[mid] && target <= nums[n-1]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};
```

#### [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)(包含重复元素)

**题目：**假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

**示例 1:**

```
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
```

**示例 2:**

```
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```

**进阶:**

    这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
    这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

**代码：**

```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len<1) return false;
        int l=0;
        int r = len;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid]){
                l++;
                continue;
            }
            if(nums[l]<nums[mid]){
                if(target>=nums[l] && target<nums[mid]) r = mid;
                else l =mid+1;
            }
            else{
                if(target>nums[mid] && target<=nums[len-1]) l = mid+1;
                else r = mid;
            }
        }
        return false; 
    }
};
```

