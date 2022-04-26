#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main() {
	int x = -2147483648;
	Solution s;
	int res = s.reverse(x);
	cout << res << endl;
	return 0;
}
