# 15. 3Sum（三数之和）

## 方法1：暴力法

### 思路与算法

3重循环。

### 复杂度分析

时间复杂度：O(n^3)。空间复杂度：O(1)。

## 方法2：排序+双指针法

### 思路与算法

为了减少重复，我们可以将数组中的元素从小到大进行排序，这样就保证了只有 (a, b, c) 这个顺序会被枚举到，而 (b, a, c)、(c, b, a) 等等这些不会，同时对于每一重循环而言，要保证相邻两次枚举的元素不能相同。接下来对于第 2 重循环，就可以采用双指针的办法，从两端向中间枚举，同样的，对于相邻两次枚举的元素不能相同，直到指向相同位置或者l > r，退出本次循环。

### 复杂度分析

时间复杂度：O(n^2)。空间复杂度：O(1)。

### C++ 解法一

```c++
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
```



