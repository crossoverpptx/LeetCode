# Median of Two Sorted Arrays

因为两个数组为正序排序，那么可以依次比较两个数组的首元素，将较小者存入一个新数组，然后向后移动，直到两个数组都遍历完，得到正序的新数组，计算新数组的中位数。该算法的时间复杂度为O(m+n)。

C++ 解法一：

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> nums;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        double res;
        while (i < m || j < n)
        {
            if (i >= m)
            {
                nums.push_back(nums2[j]);
                ++j;
                continue;
            }
            if (j >= n)
            {
                nums.push_back(nums1[i]);
                ++i;
                continue;
            }

            if (nums1[i] < nums2[j])
            {
                nums.push_back(nums1[i]);
                ++i;
            }
            else
            {
                nums.push_back(nums2[j]);
                ++j;
            }
        }

        int t = nums.size();
        if ( t % 2 == 0)
        {
            res = (nums[(t - 1) / 2] + nums[t / 2]) / 2.0;
        }
        else
        {
            res = nums[t / 2];
        }

        return res;
    }
};
```
但题目要求时间复杂度是O(log(m+n))，