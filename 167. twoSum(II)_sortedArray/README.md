#### [167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

**题目：**给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

**说明:**

    返回的下标值（index1 和 index2）不是从零开始的。
    你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

**示例:**

```
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
```

**思路1：**

```
这个是不经过优化之前，看完题目，第一想到的就是遍历数组，看每一个数，它的target-numbers[i]是否在哈希表中，不在的话，就添加到哈希表，在的话，就把target-numbers[i]对应的下标+1和i+1添加到数组中。数组就是最终返回的值。
```

**代码1：**

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> aim;
        int len = numbers.size();
        unordered_map<int,int>tmp(len);
        for(int i=0;i<len;i++){
            if(tmp.find(target-numbers[i])!=tmp.end()){
                aim.push_back(tmp[target-numbers[i]]+1);
                aim.push_back(i+1);
            }
            else {
                //tmp.insert({numbers[i],i});
                tmp.emplace(numbers[i],i);
            }
        }
        return aim;

    }
};
```

**思路2：**

```
完全利用了升序数组的前提条件，我左右夹击判断，如果加和大于目标值，右指针前移；小于目标和，左指针后移；直到加和等于目标值，就把左右指针分别加1添加到数组。
```

**代码2：**

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            if((numbers[l]+numbers[r])==target) return {l+1,r+1};
            else if((numbers[l]+numbers[r])>target) r--;
            else l++;
        }
        return {};
    }
};
```