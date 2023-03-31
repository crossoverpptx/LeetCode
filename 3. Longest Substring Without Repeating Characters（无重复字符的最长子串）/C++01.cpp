#include <iostream>
#include <unordered_map>
#include <string>

using std::string; using std::unordered_map; using std::cout; using std::endl; using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        while (right < s.size())
        {
            while (right < s.size() && !window[s[right]])
            {
                window[s[right]] = 1;
                ++right;
            }
            res = max(res, right - left);

            while (left < right)
            {
                window[s[left]] = 0;
                if (s[left++] == s[right])
                    break;
            }
        }
        return res;
    }
};

int main()
{
    string s{"abcabcbb"};
    Solution s1;
    cout << s1.lengthOfLongestSubstring(s) << endl;
    return 0;
}
