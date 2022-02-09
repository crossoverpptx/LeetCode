#include <iostream>
#include <vector>
#include <iomanip>

using std::vector; using std::cout; using std::endl; using std::fixed; using std::setprecision;

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
            res = ((double)nums[t / 2] + nums[t / 2 - 1]) / 2;
        }
        else
        {
            res = nums[(t - 1) / 2];
        }

        return res;
    }
};

int main()
{
    vector<int> nums1 = {0, 0};
    vector<int> nums2 = {};
    Solution s;
    cout << fixed << setprecision(5) <<s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
