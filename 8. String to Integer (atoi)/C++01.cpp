#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		int l = s.length(), flag = 1;
		long res = 0;

		for (int i = 0; i < l; ++i) {
			if (s[i] == ' ') {
				continue;
			}
			else if (s[i] == '+') {
				if (flag == -1) // 判断例如"-+12"的情况
					flag = -1;
				else
					flag = 1;
				continue;
			}
			else if (s[i] == '-') {
				flag = -1;
				continue;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				res = res * 10 + s[i] - '0';
			}
			else {
				break; // 若数字后有字符，结束
			}
		}
		res *= flag;

		if (res > INT_MAX || res < INT_MIN) {
			return (flag == 1) ? INT_MAX : INT_MIN;
		}
		else {
			return res;
		}
	}
};

int main() {
	string str = "+-12";
	Solution s;
	int res = s.myAtoi(str);
	cout << res << endl;
	return 0;
}
