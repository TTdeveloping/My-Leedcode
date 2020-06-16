#pragma once
#include<iostream>
#include<vector>
# include<algorithm>
using namespace std;
class Solution1 {
public:
	int numWays(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		
		return numWays(n - 2) + numWays(n - 1);
	}
};
class Solution {
public:
	int numWays(int n) {
		vector<int> dp(n+1,0);
		if (n == 0 || n == 1) return 1;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 2] + dp[i - 1])% 1000000007;
		}
		return dp[n];
	}
};