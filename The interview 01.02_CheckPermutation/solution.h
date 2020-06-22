#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include <math.h>
using namespace std;

/*class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		return s1==s2;
	}
};*/
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		int sum1 = 0, sum2 = 0;
		if (s1.size() != s2.size()) return false;
		else {
			for (int i = 0; i < s1.size(); i++) {
				sum1 += int(s1[i]);
				sum2 += int(s2[i]);
			}
		}
		return (sum1 == sum2);
	}
};