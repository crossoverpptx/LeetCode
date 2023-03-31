#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

int main() {
    Solution s;
    string str{ "cbbd" };
    cout << s.longestPalindrome(str) << endl;
    return 0;
}
