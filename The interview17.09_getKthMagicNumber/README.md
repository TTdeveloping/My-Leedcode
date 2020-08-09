#### [面试题 17.09. 第 k 个数](https://leetcode-cn.com/problems/get-kth-magic-number-lcci/)

**题目：**有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

**示例 1:**

```
输入: k = 5

输出: 9
```

**代码：**

```c++
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int>dp(k);
        int dp3=0,dp5=0,dp7=0;
        dp[0] = 1;
        for(int i=1;i<k;i++){
            dp[i]=min(dp[dp3]*3,min(dp[dp5]*5,dp[dp7]*7));
            if(dp[i]==dp[dp3]*3) dp3++;
            if(dp[i]==dp[dp5]*5) dp5++;
            if(dp[i]==dp[dp7]*7) dp7++;
        }
        return dp[k-1];
    }
};
```

