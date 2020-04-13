#include <iostream>
#include "soultion.h"
#include<unordered_map>
int main()
{
	Solution so;
	string s = "MCMXCIV" ;
	int result = so.romanToInt(s);
	std::cout << result << std::endl;
	
	std::cout << std::endl << "Test Finished." << std::endl;
	std::getchar();

	return 0;
};