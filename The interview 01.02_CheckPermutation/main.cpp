#include"solution.h"
int main() {
	Solution s;
	string s1 = "aabcdaaaad", s2 = "aabcdaaaab";
	auto result = s.CheckPermutation(s1, s2);
	cout << boolalpha << endl;
	cout << result << endl;
	cout << "Test final" << endl;
	getchar();
	return 0;
}