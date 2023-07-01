#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> numsMap;
		std::vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			numsMap.insert(std::pair<int, int>(nums[i], i)); // 建立索引与值的哈希表
		}
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = numsMap.find(target - nums[i]);
			if (iter != numsMap.end() && iter->second != i) 
			{
				ans.emplace_back(i);
				ans.emplace_back(iter->second);
				return ans;
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
