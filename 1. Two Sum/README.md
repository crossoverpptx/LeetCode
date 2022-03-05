# README

**暴力法**

这道题给了我们一个数组，还有一个目标数target，让找到两个数字，使其和为target。

乍一看就感觉可以用暴力搜索，但这个算法的时间复杂度是O(n^2)。

C++ 解法一：

```c++
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
```

**哈希表法**

由于暴力搜索的方法是遍历所有的两个数字的组合，然后算其和，这样虽然节省了空间，但是时间复杂度高。一般来说，为了提高时间的复杂度，需要用空间来换，这算是一个trade off吧，这里只想用线性的时间复杂度来解决问题，就是说只能遍历一个数字，那么另一个数字呢？可以事先将其存储起来，使用一个哈希表，来建立数字和其坐标位置之间的映射，由于哈希表是常数级的查找效率，这样在遍历数组的时候，用target减去遍历到的数字，就是另一个需要的数字了，直接在哈希表中查找其是否存在即可，注意要判断查找到的数字不是第一个数字，比如target是4，遍历到了一个2，那么另外一个2不能是之前那个2，整个实现步骤为：先遍历一遍数组，建立哈希表映射，然后再遍历一遍，开始查找，找到则记录index。

 C++ 解法二：

```c++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		unordered_map<int, int> numsMap;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			numsMap.insert(pair<int, int>(nums[i], i));
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
		}
		return res;
	}
};
```

