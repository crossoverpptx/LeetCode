#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
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
