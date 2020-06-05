#include <iostream>
#include "Solution.h"
using namespace std;
int main()

{
	Solution s;
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int n = matrix[0].size()*matrix.size();
	auto re = s.spiralOrder(matrix);
	//std::cout << re << std::endl;
	for (int i = 0; i < n; i++)
	{
		cout << re[i] << endl;
	}
	getchar();//让运行的临时窗口不消失。
	
	return 0;
}
