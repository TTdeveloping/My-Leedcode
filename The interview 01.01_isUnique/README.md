#### [面试题 01.01. 判定字符是否唯一](https://leetcode-cn.com/problems/is-unique-lcci/)

**题目：**实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

**示例 1：**

```
输入: s = "leetcode"
输出: false 
```

**示例 2：**

```
输入: s = "abc"
输出: true
```

限制：

    0 <= len(s) <= 100
    如果你不使用额外的数据结构，会很加分。

**代码：**

```
//先给数组排序，然后遍历。
class Solution {
public:
    bool isUnique(string astr) {
        if(astr.size()==0) return true; 
        sort(astr.begin(),astr.end());
        for(int i=1;i<astr.size();i++){
            if(astr[i]==astr[i-1]) return false;
        }
        return true;
    }
};
```

