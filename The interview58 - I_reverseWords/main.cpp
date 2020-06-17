#include"solution.h"
int main() {
	Solution s;
	string str = "the sky is blue";
	string result = s.reverseWords(str);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	cout << "Test final" << endl;
	getchar();
	return 0;
}