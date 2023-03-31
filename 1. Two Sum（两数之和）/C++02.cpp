#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector; using std::unordered_map; using std::pair; using std::allocator; using std::cout;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> numsMap;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			numsMap.insert(pair<int, int>(nums[i], i));
			//Method 2
			//numsMap[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			auto iter = numsMap.find(target - nums[i]);
			if (iter != numsMap.end() && iter->second != i)
			{
				res.push_back(i);
				res.push_back(iter->second);
				return res;
			}
			//Method 2
			//int t = target - nums[i];
			//if (numsMap.count(t) && numsMap[t] != i)
			//{
			//	res.push_back(i);
			//	res.push_back(numsMap[t]);
			//	break;
			//}
		}
		return res;
	}
};

int main()
{
	int ai[4] = { 4, 3, 7, 32 };
	vector<int, allocator<int>> nums(ai, ai + 4);
	//Method 2
	//vector<int> nums = { 4, 3, 7, 32 };
	int target = 10;
	Solution s;
	vector<int> result = s.twoSum(nums, target);
	for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
		cout << *it << " ";
	return 0;
}
