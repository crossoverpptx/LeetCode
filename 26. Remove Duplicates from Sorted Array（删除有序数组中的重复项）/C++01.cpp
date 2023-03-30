#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main() {
    std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    Solution s;
    int ans = s.removeDuplicates(nums);
    std::cout << ans << std::endl;
    for(auto it = nums.begin(); it != nums.begin() + ans; ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
