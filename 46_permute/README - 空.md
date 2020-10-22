#### [46. 全排列](https://leetcode-cn.com/problems/permutations/)

**题目：**给定一个 没有重复 数字的序列，返回其所有可能的全排列。

**示例:**

```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

**思路：**

```
搜索回溯。
```

**代码：**

```c++
#include<iostream>   
#include<vector> 
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
	void backtrace(vector<vector<int>>& res, vector<int>& output, int first, int len) {
		if (first == len) {
			res.emplace_back(output);
			return;
		}
		for (int i = first; i < len; i++) {
			swap(output[i], output[first]);//动态维护数组
			backtrace(res, output, first + 1,len);//递归填下一个数
			swap(output[i], output[first]);//撤销操作。
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		backtrace(res, nums, 0, nums.size());
		return res;

	}
};
int main() {
	vector<int> nums = { 1,2,3 };
	Solution s;
	auto res = s.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
	
	getchar();
	return 0;
}
```

**借用大佬的图片：**

![1603005816738](C:\Users\Admin\AppData\Roaming\Typora\typora-user-images\1603005816738.png)