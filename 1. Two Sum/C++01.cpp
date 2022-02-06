#include <iostream>
#include <vector>

using std::vector; using std::cout;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (target == nums[i] + nums[j])
				{
					res.push_back(i);
					res.push_back(j);
					return res;
				}
			}
		return res;
	}
};

int main()
{
	vector<int> nums = { 4, 3, 7, 32 };
	int target = 10;
	Solution s;
	vector<int> result = s.twoSum(nums, target);
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
		cout << *it << " ";
	return 0;
}