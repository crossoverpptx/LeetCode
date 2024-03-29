# 1. Two Sum（两数之和）

## 方法1：暴力法

### 算法与思路

这道题给了我们一个数组，还有一个目标数target，让找到两个数字，使其和为target。

乍一看就感觉可以用暴力搜索，但这个算法的时间复杂度是O(n^2)。

### C++ 解法一

```c++
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
```

## 方法2：哈希表法

### 算法与思路

由于暴力搜索的方法是遍历所有的两个数字的组合，然后算其和，这样虽然节省了空间，但是时间复杂度高。一般来说，为了提高时间的复杂度，需要用空间来换，这算是一个trade off吧，这里只想用线性的时间复杂度来解决问题，就是说只能遍历一个数字，那么另一个数字呢？可以事先将其存储起来，使用一个哈希表，来建立数字和其坐标位置之间的映射，由于哈希表是常数级的查找效率，这样在遍历数组的时候，用target减去遍历到的数字，就是另一个需要的数字了，直接在哈希表中查找其是否存在即可，注意要判断查找到的数字不是第一个数字，比如target是4，遍历到了一个2，那么另外一个2不能是之前那个2，整个实现步骤为：先遍历一遍数组，建立哈希表映射，然后再遍历一遍，开始查找，找到则记录index。

###  C++ 解法二

```c++
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
```

