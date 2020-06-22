#### [面试题 01.02. 判定是否互为字符重排](https://leetcode-cn.com/problems/check-permutation-lcci/)

**题目：**给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

**示例 1：**

```
输入: s1 = "abc", s2 = "bca"
输出: true 
```

**示例 2：**

```
输入: s1 = "abc", s2 = "bad"
输出: false
```

**说明：**

```
0 <= len(s1) <= 100
0 <= len(s2) <= 100 
```

**思路（两种方法）：**

- 分别给s1和s2排序，看排序后的是否相等。
- 分别累加这两个字符串中的字符的ASCII值，看最终的和是否相等。

**代码：**

```
方法一：
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};

方法二：
class Solution {
public:
	bool CheckPermutation(string s1, string s2){
		int sum1 = 0, sum2 = 0;
		if (s1.size() != s2.size()) return false;
		else{
			for (int i = 0; i < s1.size(); i++){
				sum1 += int(s1[i]);
				sum2 += int(s2[i]);
			}
		}
		return (sum1 == sum2);
	}
};
```

