#### [面试题 08.08. 有重复字符串的排列组合](https://leetcode-cn.com/problems/permutation-ii-lcci/)

**题目：**有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

**示例1:**

```
 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]
```

**示例2:**

```
 输入：S = "ab"
 输出：["ab", "ba"]
```

**提示:**

    字符都是英文字母。
    字符串长度在[1, 9]之间。

**代码：**

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        if S == '':
            return [];
        path = ''
        res = []
        def Backtrack(S,path,res):
            if S=='':
                res.append(path)
                return
            for i in range(len(S)):
                cur=S[i]
                Backtrack(S[:i]+S[i+1:], path+cur, res)
        Backtrack(S,path,res)
        res=list(set(res))
        return res
```

