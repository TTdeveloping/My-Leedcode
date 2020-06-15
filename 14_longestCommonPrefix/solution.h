#pragma once
#include<iostream>
#include<vector>
# include<algorithm>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size()) return "";
		string prex = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			prex = longestCommonPrefix(prex, strs[i]);
			if (!prex.size()) break;
		}
		return prex;
	}
	string longestCommonPrefix(string str1, string str2) {
		int len = min(str1.size(), str2.size());
		int index = 0;
		while (index < len && str1[index] == str2[index]) {
			index++;
		}
		string prex = str1.substr(0, index);
		return prex;
	}
};