#### [剑指 Offer 61. 扑克牌中的顺子](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

**题目：**从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。 

**示例 1:**

```
输入: [1,2,3,4,5]
输出: True
```

**示例 2:**

```
输入: [0,0,1,2,5]
输出: True
```

**限制：**

数组长度为 5 

数组的数取值为 [0, 13] .

**代码：**

```c++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<4;i++){
            if(nums[i]==0) {
                count += 1;
                continue;
            }
            else if(nums[i]==nums[i+1]) return false;
        }
        return nums[4]-nums[count]<5;
    }
};

//更好理解的写法：
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<4;i++){
            if(nums[i]==0) {
                count += 1;
                continue;
            }
            else if(nums[i]==nums[i+1]) return false;
            else{
                int gap=nums[i+1]-nums[i];
                if(gap-1>count) return false;
            }
        }
        return true;
    }
};
```

