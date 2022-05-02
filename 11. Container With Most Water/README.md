# Container With Most Water

**朴素法**

两层 for 循环，但是 OJ 判`超出时间限制`。

时间复杂度：O(n^n)。空间复杂度：O(1)。

C++ 解法一：

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

**双指针法**

定义两个指针分别指向数组两端，向中间搜索，每搜索一次计算一次值并和最大值比较。 

时间复杂度：O(n)。空间复杂度：O(1)。

C++ 解法二：

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

**双指针法 - 改进**

对上面的方法进行了小幅度的优化，对于相同的高度直接移动 i 和 j 就行了，不再进行计算容量。

时间复杂度：O(n)。空间复杂度：O(1)。

C++ 解法二：

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

