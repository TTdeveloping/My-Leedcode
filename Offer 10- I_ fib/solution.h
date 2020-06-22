#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
	int fib(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		vector<int>m(n + 1);
		m[0] = 0;
		m[1] = 1;
		for (int i = 2; i <= n; i++) {
			m[i] = (m[i - 2] + m[i - 1]) % 1000000007;
		}
		return m[n];
	}
};