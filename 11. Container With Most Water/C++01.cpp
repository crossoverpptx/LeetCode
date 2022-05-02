#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res, max = 0;
		for(int i = 0;i < height.size(); ++i)
			for (int j = i + 1; j < height.size(); ++j) {
				res = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
				if (res > max) {
					max = res;
				}
			}
		return max;
	}
};

int main() {
	vector<int> height{ 1,8,6,2,5,4,8,3,7 };
	Solution s;
	int ans = s.maxArea(height);
	cout << ans << endl;
	return 0;
}
