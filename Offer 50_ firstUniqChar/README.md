#### [剑指 Offer 50. 第一个只出现一次的字符](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/)

**题目：**在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

**示例:**

```
s = "abaccdeff"
返回 "b"

s = "" 
返回 " "

 
```

**限制：**

0 <= s 的长度 <= 50000

**我的思路：**

```
我的思路就是：如果输入的字符串s是空串就直接返回" ",如果s不为空，我们就先遍历s，将字符和它出现的次数构成key-value对放进字典里。然后遍历字典，把value值为1的放进一个列表中，如果列表为空，说明字符的出现次数都是大于1的，则返回" "，如果列表不为空，则说明有符合这样的字符，就直接返回列表中的第一个字符，它就是第一个出现一次的那个字符。
```

**代码：**

```python3
# 刚开始的写法一
class Solution:
    def firstUniqChar(self, s: str) -> str:
        if s == "":
            return " "
        tmp = {}
        for c in s:
            if c in tmp:
                tmp[c] +=1
            else:
                tmp[c]=1
        one = [k for k, v in tmp.items() if v == 1]
        if len(one) == 0:
            return " "
        else:
            return one[0]
# 受启发后优化代码二：
class Solution:
    def firstUniqChar(self, s: str) -> str:
        tmp = {}
        for c in s:
            if c in tmp:
                tmp[c] +=1
            else:
                tmp[c]=1
        for c in s:
            if tmp[c]==1:
                return c
        return " "       
```

**他人代码思路：**

```
遍历s，如果该字符不在字典中，就把该字符和true为键值对写进字典，如果在字典中的话，就用false来更新这个字符的value。然后再次遍历字符串s,看该字符串在字典中对应的value值是true就返回该字符。
这个思路其实和我的优化代码二很相像，知识value值的不同。时间上他的较短，不知道是不是leedcode执行的问题，反正遇到过很多次这种情况了。
```

**他人代码：**

```
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = {}
        for c in s:
            dic[c] = not c in dic
        for c in s:
            if dic[c]: return c
        return ' '
```

