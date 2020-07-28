#### [面试题 08.07. 无重复字符串的排列组合](https://leetcode-cn.com/problems/permutation-i-lcci/)

**题目：**无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

**示例1:**

```
 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
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

```c++
class Solution:
    def permutation(self, S: str) -> List[str]:
        if S == '' :
            return []
        path =''
        res = []
        def Backtracking(S,path,res):
            if S == '':
                res.append(path)
                return 
            for i in range(len(S)):
                cur=S[i]
                Backtracking(S[:i]+S[i+1:] , path+cur, res)
        Backtracking(S,path,res)
        return res
```

