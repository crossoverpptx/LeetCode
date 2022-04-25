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
		int c = (n + t - 1) / t * (r - 1); // 变换周期的个数向上取整 * 每个周期的列数 = 矩阵的列数
		vector<vector<char>> vec(r, vector<char>(c, 0)); //初始化一个r行c列的元素值全为0的二维矩阵
		for (int i = 0, x = 0, y = 0; i < n; ++i) {
			vec[x][y] = s[i];
			if (i % t < r - 1) {
				++x;
			}
			else {
				--x;
				++y;
			}
		}

		string res;
		for (auto row : vec) {
			for (char ch : row) {
				if (ch) {
					res += ch;
				}
			}
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
