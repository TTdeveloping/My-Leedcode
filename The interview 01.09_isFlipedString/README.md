#### [面试题 01.09. 字符串轮转](https://leetcode-cn.com/problems/string-rotation-lcci/)

**题目：**字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

**示例1:**

```
 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
```

**示例2:**

```
 输入：s1 = "aa", s2 = "aba"
 输出：False
```

**提示：**

```
字符串长度在[0, 100000]范围内。
```

说明:

```
你能只调用一次检查子串的方法吗？
```

**思路：**

遍历字符串s1，每次都取出s1的第一个字符，添加到s1的后面，并把这个字符从s1的第一个位置删掉。注意，每次删掉第一个字符，下面的字符就会自动往前移动。具体可见代码。

**代码：**

```
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		else if (s1.size() == 0 && s2.size() == 0) return true;
		else {
			int i = 0;
			int len = s1.size();
			while (i <= len) {
				char tem = s1[0];
				s1.erase(0, 1);
				s1 += tem;
				if (s1 != s2) i++;
				else return true;
			}
			return false;
		}

	}
};
```