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

		int t = 2 * r - 2; // �任����
		int c = (n + t - 1) / t * (r - 1); // �任���ڵĸ�������ȡ�� * ÿ�����ڵ����� = ���������
		vector<vector<char>> vec(r, vector<char>(c, 0)); //��ʼ��һ��r��c�е�Ԫ��ֵȫΪ0�Ķ�ά����
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
