#pragma once
#include<iostream>
#include<vector>
# include<algorithm>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		if (s.empty()) return "";
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		int j = s.size()-1,i=j;
		vector<string> temp;
		while (i >= 0) {
			while (i>=0 && s[i] != ' ') i--;
			temp.push_back(s.substr(i + 1, j-i));
			while (i>=0 && s[i] == ' ') i--;
			j = i; 
		}
		string str = "";
		int k = 0;
		for (int k = 0; k < temp.size(); k++) {
			if(k==temp.size()-1)str += temp[k];
			else str += temp[k] + " ";
		}
		return str;
	}
};