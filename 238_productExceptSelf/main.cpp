#include <iostream>
#include "Solution.h"
using namespace std;
int main()

{
	Solution s;
	vector<int> nums = { 1,2,3,4 };
	int n = nums.size();
	auto re = s.productExceptSelf(nums);
	//std::cout << re << std::endl;
	for (int i = 0; i < n; i++)
	{
		cout << re[i] << endl;
	}
	getchar();//让运行的临时窗口不消失。
	
	return 0;
}
