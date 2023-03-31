# 11. Container With Most Water（盛最多水的容器）

## 方法1：朴素法

### 算法与思路

两层 for 循环，但是 OJ 判`超出时间限制`。

### 复杂度分析

时间复杂度：O(n^n)。空间复杂度：O(1)。

### C++ 解法一

```c++
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
```

## 方法2：双指针法

### 算法与思路

定义两个指针分别指向数组两端，向中间搜索，每搜索一次计算一次值并和最大值比较。 

### 复杂度分析

时间复杂度：O(n)。空间复杂度：O(1)。

### C++ 解法二

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        return res;
    }
};
```

## 方法3：双指针法 - 改进

### 思路与算法

对上面的方法进行了小幅度的优化，对于相同的高度直接移动 i 和 j 就行了，不再进行计算容量。

### 复杂度分析

时间复杂度：O(n)。空间复杂度：O(1)。

### C++ 解法三

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return res;
    }
};
```

