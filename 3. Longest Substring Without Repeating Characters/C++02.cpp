#include <iostream>
#include <unordered_set>
#include <string>

using std::string; using std::unordered_set; using std::cout; using std::endl; using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0, left = 0, i = 0;
        unordered_set<char> t;
        while (i < s.size())
		{
            if (!t.count(s[i])) 
            {
                t.insert(s[i++]);
                res = max(res, (int)t.size());
            }
            else 
            {
                t.erase(s[left++]);
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
