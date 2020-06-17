#include"solution.h"
int main() {
	Solution s;
	vector<int> nums = {1,2,3,4,5,6,7,9,9,9,9};
	auto result = s.exchange(nums);
	if (result.size() != 0) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}
	cout << "Test final" << endl;
	getchar();
	return 0;
}