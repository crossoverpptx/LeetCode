#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        return res;
    }
};

int main() {
	vector<int> height{ 1,8,6,2,5,4,8,3,7 };
	Solution s;
	int ans = s.maxArea(height);
	cout << ans << endl;
	return 0;
}
