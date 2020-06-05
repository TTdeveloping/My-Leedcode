#pragma once
#include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return {};
		}
		int columns = matrix[0].size(), rows = matrix.size();
		int top = 0, bottom = rows - 1,left = 0, right = columns - 1;
		vector<int> order;
		while (left <= right && top <= bottom)
		{
			for (int column = left; column <= right; column++)
			{
				order.push_back(matrix[top][column]);
			}
			for (int row = top + 1; row <= bottom; row++)
			{
				order.push_back(matrix[row][right]);
			}
			if (left < right && top < bottom)
			{
				for (int column = right - 1; column > left; column--)
				{
					order.push_back(matrix[bottom][column]);
				}
				for (int row = bottom; row > top; row--)
				{
					order.push_back(matrix[row][left]);
				}
			}
			left++;
			top++;
			right--;
			bottom--;
		}
		return order;


	}
};