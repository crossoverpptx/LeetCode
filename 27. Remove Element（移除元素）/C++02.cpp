#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2, ans = 0;

    Solution s;
    ans = s.removeElement(nums, val);

    cout << ans << ", nums = ";
    cout << "[";
    for(vector<int>::iterator it = nums.begin(); it != nums.begin() + ans; ++it) {
        if(it != nums.begin() + ans - 1) {
            cout << *it << ", ";
        }else {
            cout << *it;
        }
    }
    cout << "]\n";

    return 0;
}