#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};

int main() {
	int x = -2147483648;
	Solution s;
	int res = s.reverse(x);
	cout << res << endl;
	return 0;
}
