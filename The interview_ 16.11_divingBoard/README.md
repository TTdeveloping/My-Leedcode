#### [面试题 16.11. 跳水板](https://leetcode-cn.com/problems/diving-board-lcci/)

**题目：**你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

**示例：**

```
输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
```

**提示：**

    0 < shorter <= longer
    0 <= k <= 100000

**代码：**

```
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k==0) return vector<int>();
        if(shorter==longer) return vector<int>(1,shorter*k);
        vector<int>result(k+1);
        for(int i=0;i<=k;i++){
            result[i] = longer*i + shorter*(k-i);
        }
        return result;
    }
};
```

**总结：**

虽然这个题不难，但是我从中学到了c++很多基础知识，如下：

假如声明一个空的整型vector的写法为：vector<int>()

假如声明一个只装5个数的整型vector的写法为：vector<int>(5)

假如声明一个只装5个数的整型vector，且这五个数都为2的写法为：vector<int>(5,2)

