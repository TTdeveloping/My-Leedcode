#### [剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)

**题目：**请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

**示例 1:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

**提示：**

    s.length <= 40000

**思路：**

```
动态规划+哈希表。用哈希表来存储字符串中每一个字符的最近的一个位置索引。声明两个变量，tmp用来表示每一步的不重复子字符串的长度；res来存储最大的子字符串的长度。最后res就是我们需要的值。我分别用了c++和python语言来写，过程惨不忍睹，语言之间的切换，力不从心，之前一直用c++刷题的，后来总结了一下，有些题用python写更简便，就想把python捞起来，谁知状况百出，还是灵活一些更好。c++和python都要经常写一写的。
```

**代码（c++）:**

```c++
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int>dict;
		int i;
		int tmp=0, res=0;
		for (int j = 0; j < s.size(); j++) {
			if (dict.count(s[j]) !=0) i = dict[s[j]];
			else i = -1;
			dict[s[j]] = j;
			tmp = tmp < j - i ? tmp + 1 : j - i;
			res = max(res, tmp);
		}
		return res;
	}
};
```

**代码（python）:**

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dict = {}
        tmp=res=0
        for j in range(len(s)):
            i = dict.get(s[j],-1)
            dict[s[j]] =j
            tmp=tmp+1 if tmp<j-i else j-i
            res = max(res,tmp)
        return res
```

