# 16. 3Sum Closest（最接近的三数之和）

## 方法1：暴力法

### 思路与算法

3重循环。

### 复杂度分析

时间复杂度：O(n^3)。空间复杂度：O(1)。

## 方法2：排序+双指针法

### 思路与算法

这道题让我们求最接近给定值的三数之和，是在之前那道 3Sum 的基础上又增加了些许难度。这道题让返回这个最接近于给定值的值，即要保证当前三数和跟给定值之间的差的绝对值最小，所以需要定义一个变量 diff 用来记录差的绝对值。首先还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，然后用两个指针 left 和 right 来滑动寻找另外两个数，每确定两个数，求出此三数之和，然后算和给定值的差的绝对值存在 newDiff 中，然后和 diff 比较并更新 diff 和结果 closest 即可。

### 复杂度分析

时间复杂度：O(N^2)。空间复杂度：O(logN)。排序需要使用 O(logN) 的空间。然而我们修改了输入的数组 nums，在实际情况下不一定允许，因此也可以看成使用了一个额外的数组存储了 nums 的副本并进行排序，此时空间复杂度为 O(N)。

### C++ 解法一

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }

        return closest;
    }
};
```

## 方法3：排序+双指针法 - 优化

### 思路与算法

我们可以稍稍将**排序+双指针法**进行一下优化，每次判断一下，当 nums[i]*3 > target 的时候，就可以直接比较 closest 和 nums[i] + nums[i+1] + nums[i+2] 的值，返回较小的那个，因为数组已经排过序了，后面的数字只会越来越大，就不必再往后比较了。

### C++ 解法二

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] * 3 > target) return min(closest, nums[i] + nums[i + 1] + nums[i + 2]);
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }

        return closest;
    }
};
```