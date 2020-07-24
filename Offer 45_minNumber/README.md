#### [剑指 Offer 45. 把数组排成最小的数](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/)

**题目：**输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。 

**示例 1:**

输入: [10,2]
输出: "102"

**示例 2:**

输入: [3,30,34,5,9]
输出: "3033459"

**提示:**

    0 < nums.length <= 100

**说明:**

    输出结果可能非常大，所以你需要返回一个字符串而不是整数
    拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

**代码：**

```c++
//写法一：用冒泡排序对字符串排序：
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>s;
        string res;
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        for(int i=0;i<s.size()-1;i++){
            for(int j=0;j<s.size()-1-i;j++){
               if(s[j]+s[j+1]>s[j+1]+s[j]){
                   swap(s[j],s[j+1]);
               }
            }    
        }
        for(int i=0;i<s.size();i++) res+=s[i];
        return res;
    }
};
写法二：参考别人的写法（应该是lambda表达式）
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>s;
        string res;
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(),s.end(),[](string& s1, string& s2){return s1+s2 < s2+s1;});//字符排序
        for(int i=0;i<s.size();i++) res+=s[i];
        return res;
    }
};

```

