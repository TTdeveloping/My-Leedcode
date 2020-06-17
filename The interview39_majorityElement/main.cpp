#include"solution.h"
int main() {
	Solution1 s;
	vector<int> nums = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	auto result = s.majorityElement(nums);
	
	cout << result << endl;
		
	
	cout << "Test final" << endl;
	getchar();
	return 0;
}