#include"solution.h"
int main() {
	Solution s;
	vector<string>str_list = { "flower","flow","flight" };
	string result = s.longestCommonPrefix(str_list);
	if (result.size() != 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}
	else {
		cout << "" << endl;
	}
	getchar();
	return 0;
}