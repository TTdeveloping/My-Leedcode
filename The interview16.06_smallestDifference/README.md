#### [面试题 16.06. 最小差](https://leetcode-cn.com/problems/smallest-difference-lcci/)

**题目：**给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差

**示例：**

```
输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
输出： 3，即数值对(11, 8)
```

**提示：**

    1 <= a.length, b.length <= 100000
    -2147483648 <= a[i], b[i] <= 2147483647
    正确结果在区间[-2147483648, 2147483647]内

**代码：**

```c++
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long res = INT_MAX;
        for(int i=0, j=0;i<a.size()&&j<b.size();){
            res = min(res,abs(long(a[i])-long(b[j])));
            if(a[i]<b[j]) i++;
            else j++;
        }
        return res;
    }
};
```

