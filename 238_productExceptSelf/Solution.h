#pragma once
#include <iostream>
# include <vector>
using namespace std;

class Solution 
{
public:
	vector<int> productExceptSelf(vector<int>& nums) 
	{
		int n = nums.size();
		int left = 1;
	    vector<int> Output(n);
		for (int i = 0; i < n; i++)
		{
			Output[i] = left;
			left = left * nums[i];
		}
		int right = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			Output[i] *= right;
			right *= nums[i];
		}
		return Output;

	}

};