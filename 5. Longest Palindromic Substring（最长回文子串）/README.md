# 5. Longest Palindromic Substring（最长回文子串）

## 方法1：中心扩展法

### 思路与算法

传统的验证回文串的方法就是两个两个的对称验证是否相等，那么对于此问题，就是要以每个字符为中心，向两边扩散来寻找回文串，需要注意的是，由于回文串长度可奇可偶，对于奇数形式，就从遍历中心向两边扩散即可；对于偶数形式，就要把当前位置及下一个位置当做最中间的两个字符，然后向两边搜索。

### C++ 解法一

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

## 方法2：动态规划法

### 思路与算法

此题可以用动态规划法解，即维护一个二维数组 dp，其中 dp[i][j]表示字符串区间 [i, j] 是否为回文串。当 i = j 时，只有一个字符，肯定是回文串；如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]；如果 i 和 j 不相邻，即 i - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，dp[i + 1][j - 1] 若为真，就是回文串。通过以上分析，可以写出递推式如下：

```c++
dp[i][j] = 1，当 i = j 时；
dp[i][j] = s[i] == s[j]，当 j = i + 1 时；
dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1]，当 j > i + 1 时。
```

### C++ 解法二

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())   return "";

        int n = s.size(), left = 0, maxLen = 1;   // 定义最长回文子串左边界及长度
        vector<vector<int>> dp(n, vector<int>(n));  // 定义 dp 数组
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;   // 单个字符均是回文串
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j]) && (i - j < 2 || dp[j + 1][i - 1]);
                if (dp[j][i] && (i - j + 1 > maxLen)) {
                    left = j;
                    maxLen = i - j + 1;
                }
            }
        }

        return s.substr(left, maxLen);
    }
};
```

## 方法3：Manacher 算法

