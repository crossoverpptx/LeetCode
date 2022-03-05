# Median of Two Sorted Arrays

**暴力法**

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
**二分法**

但题目要求时间复杂度是O(log(m+n))，很自然想到了二分法。回顾一下中位数的定义，如果某个有序数组长度是奇数，那么其中位数就是最中间那个，如果是偶数，那么就是最中间两个数字的平均值。这里对于两个有序数组也是一样的，假设两个有序数组的长度分别为m和n，由于两个数组长度之和m+n的奇偶不确定，因此需要分情况来讨论，对于奇数的情况，直接找到最中间的数即可，偶数的话需要求最中间两个数的平均值。为了简化代码，不分情况讨论，使用一个小trick，分别找第(m+n+1) / 2个，和(m+n+2) / 2个，然后求其平均值即可，这对奇偶数均适用。若m+n为奇数的话，那么其实(m+n+1) / 2和(m+n+2) / 2的值相等，相当于两个相同的数字相加再除以2，还是其本身。

那么问题就变成了寻找两个有序数组的第K个元素，可以定义一个函数来在两个有序数组中找到第K个元素。首先，为了避免拷贝产生新的数组从而增加时间复杂度，使用两个变量i和j分别来标记数组nums1和nums2的起始位置。然后来处理一些corner cases，比如当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，相当于一个空数组了，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了。还有就是如果K=1的话，只要比较nums1和nums2的起始位置i和j上的数字就可以了。难点就在于一般的情况怎么处理？因为需要在两个有序数组中找到第K个元素，为了加快搜索的速度，可以使用二分法，那么对谁二分呢，数组么？其实要对K二分，意思是需要分别在nums1和nums2中查找第K/2个元素，注意这里由于两个数组的长度不定，所以有可能某个数组没有第K/2个数字，所以需要先check一下数组中到底存不存在第K/2个数字，如果存在就取出来，否则就赋值上一个整型最大值（目的是要在nums1或者nums2中先淘汰K/2个较小的数字，判断的依据就是看midVal1和midVal2谁更小，但如果某个数组的个数都不到K/2个，自然无法淘汰，所以将其对应的midVal值设为整型最大值，以保证其不会被淘汰），若某个数组没有第K/2个数字，则淘汰另一个数组的前K/2个数字即可。举个例子来说吧，比如nums1 = {3}，nums2 = {2, 4, 5, 6, 7}，K=4，要找两个数组混合中第4个数字，则分别在nums1和nums2中找第2个数字，而nums1中只有一个数字，不存在第二个数字，则nums2中的前2个数字可以直接跳过，为啥呢，因为要求的是整个混合数组的第4个数字，不管nums1中的那个数字是大是小，第4个数字绝不会出现在nums2的前两个数字中，所以可以直接跳过。

有没有可能两个数组都不存在第K/2个数字呢，这道题里是不可能的，因为K不是任意给的，而是给的m+n的中间值，所以必定至少会有一个数组是存在第K/2个数字的。最后就是二分法的核心了，比较这两个数组的第K/2小的数字midVal1和midVal2的大小，如果第一个数组的第K/2个数字小的话，那么说明要找的数字肯定不在nums1中的前K/2个数字，可以将其淘汰，将nums1的起始位置向后移动K/2个，并且此时的K也自减去K/2，调用递归，举个例子来说吧，比如nums1 = {1, 3}，nums2 = {2, 4, 5}，K=4，要找两个数组混合中第4个数字，那么分别在nums1和nums2中找第2个数字，nums1中的第2个数字是3，nums2中的第2个数字是4，由于3小于4，所以混合数组中第4个数字肯定在nums2中，可以将nums1的起始位置向后移动K/2个。反之，淘汰nums2中的前K/2个数字，并将nums2的起始位置向后移动K/2个，并且此时的K也自减去K/2，调用递归即可。

C++ 解法二：

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) 
    {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) 
        {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        else 
        {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};
```

