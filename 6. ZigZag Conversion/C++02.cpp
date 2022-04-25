#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int n = s.length(), r = numRows;
		if (r == 0 || r == 1 || r >= n) {
			return s;
		}

		int t = 2 * r - 2; // 变换周期
		vector<string> vec(r); //初始化一个r行的二维矩阵
		for (int i = 0, x = 0; i < n; ++i) {
			vec[x] += s[i];
			i% t < r - 1 ? ++x : --x;
		}

		string res;
		for (auto row : vec) {
			res += row;
		}

		return res;
	}
};

int main() {
	string str = "PAYPALISHIRING";
	int numRows = 4;
	Solution s;
	string res = s.convert(str, numRows);
	cout << res << endl;
	return 0;
}
