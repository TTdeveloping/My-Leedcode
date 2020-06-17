#### [面试题58 - I. 翻转单词顺序](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/)

**题目：**输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

**示例 1：**

输入: "the sky is blue"
       输出: "blue is sky the"

**示例 2：**

输入: "  hello world!  "
       输出: "world! hello"
       解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

**示例 3：**

输入: "a good   example"
       输出: "example good a"
       解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

**说明：**

    无空格字符构成一个单词。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。



**我的解题思路：**

我是拿到一个字符串，是先去除首尾的空白字符，然后定义变量i和j来找到每一个单词并将它们都添加到一个列表中，最后循环遍历列表，将它们连成字符串，并去掉字符串最后的空格。

**拓展：**

有人用到了栈，就是利用栈的后进先出的特点，将压入栈中的元素进行翻转连接成字符串。比我的那种，先将单词添加到列表，然后再循环遍历列表中的单词进行连接精妙。

```
class Solution {
public:
	stack <string> words;
	string result = "";
	string reverseWords(string s) {
		if (s == "")
			return "";
		int startIndex = 0;
		int endIndex = 0;
		int length = s.length();
		while (startIndex < length)
		{
			while (s[startIndex] == ' '&&startIndex < length)
			{
				startIndex++;
			}

			endIndex = startIndex;
			while (s[endIndex] != ' '&&endIndex < length)
			{
				endIndex++;
			}
			if (startIndex != length)
			{

				words.push(s.substr(startIndex, endIndex - startIndex));

			}
			startIndex = endIndex + 1;
		}

		while (!words.empty())
		{

			result += words.top();
			result += ' ';
			words.pop();
		}
		if (result != "")
		{
			result.pop_back();
		}
		return result;

	}
};
```

