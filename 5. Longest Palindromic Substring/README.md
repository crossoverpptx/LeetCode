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

**动态规划法**

```c++
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2) 
        {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= n; L++)
        {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++)
            {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i < 3)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
```