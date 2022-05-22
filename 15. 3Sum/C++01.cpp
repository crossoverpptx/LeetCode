#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());		// 排序
		for (int i = 0; i < nums.size(); ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;	// 第 3 个数去重
			// 双指针法
			int l = i + 1, r = nums.size() - 1;
			int target = 0 - nums[i];
			while (l < r) {
				if (nums[l] + nums[r] == target) {
					ans.push_back({ nums[i],nums[l],nums[r] });
					while (l < r && nums[l] == nums[l + 1]) l++;
					while (l < r && nums[r] == nums[r - 1]) r--;
					l++, r--;
				}else if (nums[l] + nums[r] < target) {
					l++;
				}else {
					r--;
				}
			}
		}
		return ans;
    }
};

int main() {
	vector<int> nums{ -1,0,1,2,-1,-4 };
	Solution s;
	vector<vector<int>> ans = s.threeSum(nums);
	cout << "[";
	for (int i = 0; i < ans.size(); ++i) {
		cout << "[";
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << ",";
		}
		cout << "]";
	}
	cout << "]";
	return 0;
}
