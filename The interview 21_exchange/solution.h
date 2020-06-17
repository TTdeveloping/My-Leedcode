#pragma once
#include<iostream>
#include<vector>
# include<algorithm>
# include<stack>
using namespace std;

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		vector<int> j;
		vector<int> o;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] % 2 != 0) j.push_back(nums[i]);
			if (nums[i] % 2 == 0) o.push_back(nums[i]);
		}
		j.insert(j.end(), o.begin(), o.end());
		return j;
	}
};