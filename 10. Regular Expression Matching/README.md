# Regular Expression Matching

**递归法**

递归法要分的情况比较复杂，主要分以下几种情况：

- 若 p 为空，若 s 也为空，返回 true，否则返回 false。

- 若 p 的长度为1，若 s 长度也为1，且相同或是 p 为 '.' 则返回 true，否则返回 false。

- 若 p 的第二个字符不为 *，若此时 s 为空返回 false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。

- 若 p 的第二个字符为 *，进行下列循环，条件是若 s 不为空且首字符匹配（包括 p[0] 为 '.'），调用递归函数匹配 s 和去掉前两个字符的 p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配），若匹配返回 true，否则 s 去掉首字母（因为此时首字母匹配了，我们可以去掉 s 的首字母，而 p 由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。

- 返回调用递归函数匹配 s 和去掉前两个字符的 p 的结果（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，返回 true。再举个例子，比如 s="", p="a"，由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，返回 true）。

时间复杂度：O((s+p)*2^(s+p/2))。空间复杂度：O((s+p)\*2^(s+p/2))。

C++ 解法一：

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};
```

**动态规划法**

设动态规划矩阵 dp，`dp[i][j]`代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配。由于`dp[0][0]`代表的是空字符的状态，因此`dp[i][j]`对应的添加字符是`s[i-1]`和`p[j-1]`。

1) 初始化 dp 矩阵各元素值为 false，并设置`dp[0][0]==true`：代表两个空字符串能匹配。

2) 当`p[j-1] = '*'`时，`dp[i][j]`在当以下任一情况为 true 时等于 true ：
	a. `dp[i][j-2]`：即将字符组合`p[j-2]*`看做出现0次时，能否匹配；
	b. `dp[i-1][j]`且`s[i-1] = p[j-2]`：即让字符`p[j-2]`多出现1次时，能否匹配；
	c. `dp[i-1][j]`且`p[j-2] = '.'`：即让字符`'.'`多出现1次时，能否匹配。

3) 当`p[j-1] != '*'`时，`dp[i][j]`在当以下任一情况为 true 时等于 true ：
	a. `dp[i-1][j-1]`且`s[i-1] = p[j-1]`：即让字符`p[j-1]`多出现1次时，能否匹配；
	b. `dp[i-1][j-1]`且`p[j-1] = '.'`：即让字符`'.'`看做字符`s[i-1]`时，能否匹配。

[视频详解地址](https://leetcode-cn.com/problems/regular-expression-matching/solution/shi-pin-tu-jie-dong-tai-gui-hua-zheng-ze-biao-da-s/)

时间复杂度：O(m\*n)。空间复杂度：O(m\*n)。

C++ 解法二：

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
```

