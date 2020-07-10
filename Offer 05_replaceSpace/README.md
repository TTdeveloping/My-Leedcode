#### [剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)

**示例 1：**

```
输入：s = "We are happy."
输出："We%20are%20happy." 
```

**限制：**

0 <= s 的长度 <= 10000

**思路：**

大家应该都知道，字符串的题用Python做非常简单。但是python的函数也要掌握才行。乳沟是空串的话，直接返回s空串，如果不为空串且存在空格，则进行替换。看了别人代码，掌握replace()函数。存在我要替换的，我就实行替换操作后返回更新后的字符串；不存在要替换的，我就直接返回原字符串。

**我的代码：**

```pyhon3
class Solution:
    def replaceSpace(self, s: str) -> str:
        if len(s) > 0 and " " in s:
            s = s.replace(" ", "%20")
        return s
```

**别人代码：**

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(" ", "20%")
```

