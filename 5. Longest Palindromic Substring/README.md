# Longest Palindromic Substring

**中心扩展法**

传统的验证回文串的方法就是两个两个的对称验证是否相等，那么对于此问题，就是要以每个字符为中心，向两边扩散来寻找回文串，需要注意的是，由于回文串长度可奇可偶，对于奇数形式，就从遍历中心向两边扩散即可；对于偶数形式，就要把当前位置及下一个位置当做最中间的两个字符，然后向两边搜索。

C++ 解法一：

```c++
class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            searchPalindrome(s, i, i, start, maxLen);
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

    void searchPalindrome(string s, int left, int right, int& start, int& maxLen)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left; ++right;
        }
        if (maxLen < right - left - 1)
        {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};
```