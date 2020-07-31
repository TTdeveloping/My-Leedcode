#### [面试题 01.03. URL化](https://leetcode-cn.com/problems/string-to-url-lcci/)

**题目：**URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

**示例1:**

```
 输入："Mr John Smith    ", 13
 输出："Mr%20John%20Smith"
```

**示例2:**

```
 输入："               ", 5
 输出："%20%20%20%20%20"
```

提示：

    字符串长度在[0, 500000]范围内。

**代码：**

```python3
//利用python切片方法，将字符串切下来到指定长度，因为前边的空格加上字符够不够length我们没法判定，所以我们直接截取指定长度，然后在指定长度的字符串中，将空格都替换成“%20”,Perfect!
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[:length].replace(" ","%20")
```

