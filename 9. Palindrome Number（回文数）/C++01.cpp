#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		else {
			string str = "";
			while (x) {
				str += (x % 10 + '0');
				x /= 10;	
			}

			char* p, * q;
			p = &str[0];
			q = p;
			while (*q) {
				q++;
			}
			q--;

			while (p <= q) {
				if (*p == *q) {
					p++;
					q--;
				}
				else {
					return false;
				}
			}
			return true;
		}
	}
};

int main() {
	int x = 121;
	Solution s;
	bool res = s.isPalindrome(x);
	cout << res << endl;
	return 0;
}
