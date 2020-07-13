#### [349. 两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/)

**题目：**给定两个数组，编写一个函数来计算它们的交集。

**示例 1：**

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

**示例 2：**

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4] 
```

**说明：**

    输出结果中的每个元素一定是唯一的。
    我们可以不考虑输出结果的顺序。

**思路：**

根据示例可看出，最终结果以列表的形式给出。并且在说明中给出输出的列表中，每个元素只占一个，就是如果一个元素在nums1和nums2中都出现，出现次数大于等于1，输出时，只输出一个。用哈希表存储解决。

**代码：**

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()) return intersection(nums2,nums1);
        unordered_map<int,int>um;
        vector<int>result;
        for(int num:nums1){
            if(um.count(num)==0) um[num]=1;
            else continue;
        }
        for(int num :nums2){
            if(um.count(num)!=0){
                result.push_back(num);
                um[num]--;
                if(um[num]==0) um.erase(num);
            }
        }
        return result;

    }
};
```

#### [350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)

**题目：**给定两个数组，编写一个函数来计算它们的交集。

**示例 1：**

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
```

**示例 2:**

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9] 
```

**说明：**

    输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
    我们可以不考虑输出结果的顺序。

**进阶：**

    如果给定的数组已经排好序呢？你将如何优化你的算法？
    如果 nums1 的大小比 nums2 小很多，哪种方法更优？
    如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

**思路1：**

这个题在说明中给出，输出列表中元素出现的个数应该和nums1或者nums2中这个元素的出现次数最少保持一致，如果nums1和nums2中这个元素出现的次数都大于1呢，说明这个输出结果，一个元素可以重复出现。这要和数组中出现最少的保持一致就行了。这和349题思路一样只是在哈希表添加那一块不同。

**代码1：**

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()<nums2.size()) return intersect(nums2,nums1);
        unordered_map<int,int>um;
        vector<int>result;
        for(int num:nums1){
            if(um.count(num)==0) um[num]=1;
            else um[num]++;
        }
        for(int num :nums2){
            if(um.count(num)!=0){
                result.push_back(num);
                um[num]--;
                if(um[num]==0) um.erase(num);
            }
        }
        return result;

    }
};
```

**思路2：**

如果给定的数组排好序如何？那我们就先给两个数组排序，然后按照排序后的进行。首先对两个数组进行排序，然后使用两个指针遍历两个数组。

初始时，两个指针分别指向两个数组的头部。每次比较两个指针指向的两个数组中的数字，如果两个数字不相等，则将指向较小数字的指针右移一位，如果两个数字相等，将该数字添加到答案，并将两个指针都右移一位。当至少有一个指针超出数组范围时，遍历结束。

**代码2：**

```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>result;
        int len1=nums1.size(),len2=nums2.size();
        int idx1=0, idx2=0;
        while(idx1<len1 && idx2<len2){
            if(nums1[idx1]<nums2[idx2]) idx1++;
            else {
                if(nums1[idx1]>nums2[idx2]) idx2++;
                else{
                    result.push_back(nums1[idx1]);
                    idx1++;
                    idx2++;
                }
            }
        }
        return result;
    }
};
```

