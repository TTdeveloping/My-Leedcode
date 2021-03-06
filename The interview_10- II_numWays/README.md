#### [面试题10- II. 青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/)

**题目：**一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例 1：**

```
输入：n = 2
输出：2
```

**示例 2：**

```
输入：n = 7
输出：21
```

**提示：**

- `0 <= n <= 100`

**解题思路：**

此题和<u>爬楼梯（[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)）</u>的解题思路是一致的，都是一道dp题。每次有两种走法，要么走一步，要么走两步。所以可以看出，1和2是看做最小的，不能再分割。值得注意：dp(0)=1；当n=1阶时，只有一种走法，所以dp(1)=1；当n=2阶时，dp(2)=2； dp(3)=dp(1)+dp(2)......以此类推。

