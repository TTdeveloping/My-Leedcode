#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution1 {
public:
	int majorityElement(vector<int>& nums){
		int aim = nums.size()/2;
		unordered_map<int, int> count;
		unordered_map<int, int>::iterator it;
		int f;
		for (int i = 0; i < nums.size(); i++) {
			if (count.find(nums[i]) == count.end()) {
				count[nums[i]] = 1;
			}
			else count[nums[i]] += 1;
		}
		for (it = count.begin(); it != count.end(); it++) {
			if (it->second > aim) {
				 f = int(it->first);
			}
		}
		return f;

	}
};

class Solution2 {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() % 2 == 0) return nums[1 / 2 * nums.size() - 1 / 2];
		else return nums[nums.size() / 2];
	}
};

class Solution3 {
public:
	int majorityElement(vector<int>& nums) {
		int x = 0, votes = 0;
		for (int num : nums) {
			if (votes == 0) x = num;
			votes += num == x ? 1 : -1;
		}
		return x;
	}
};
