#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
	int romanToInt(string s)
	{
		unordered_map <string, int> record;
		record.insert({ "I", 1 });
		record.insert({ "IV", 4 });
		record.insert({ "V", 5 });
		record.insert({ "IX", 9 });
		record.insert({ "X", 10 });
		record.insert({ "XL", 40 });
		record.insert({ "L", 50 });
		record.insert({ "XC", 90 });
		record.insert({ "C", 100 });
		record.insert({ "CD", 400 });
		record.insert({ "D", 500 });
		record.insert({ "CM", 900 });
		record.insert({ "M", 1000 });
		int i, sum = 0;
		for (i = 0; i < s.size();)
		{
			if (i + 1< s.size()&& record.find(s.substr(i, 2)) != record.end())
			{
				sum += record[s.substr(i, 2)];
				i += 2;
			}
			else
			{
				sum += record[s.substr(i,1)];
				i++;
			}p
		}
		return sum;

	}

};