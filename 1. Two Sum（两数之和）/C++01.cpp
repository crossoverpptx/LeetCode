#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int len = nums.size();
        std::vector<int> ans;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if(nums[i] + nums[j] == target) {
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution s;
    std::vector<int> ans = s.twoSum(nums, target);
    for(auto a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    return 0;
}
