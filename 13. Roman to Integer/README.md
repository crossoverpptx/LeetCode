# Roman to Integer

**模拟法**

1. 通常情况下，罗马数字中小的数字在大的数字的右边。若输入的字符串满足该情况，那么可以将每个字符视作一个单独的值，累加每个字符对应的数值即可。

2. 若存在小的数字在大的数字的左边的情况，根据规则需要减去小的数字。对于这种情况，我们也可以将每个字符视作一个单独的值，若一个数字右侧的数字比它大，则将该数字的符号取反。

时间复杂度：O(n)。空间复杂度：O(1)。

C++ 解法一：

```c++
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            }
            else {
                ans += value;
            }
        }
        return ans;
    }
};
```

**模拟法 - 反向**


与上面方法相反，也可以跟前面的数字比较。如果小于等于前面的数字，先加上当前的数字；如果大于的前面的数字，加上当前的数字减去二倍前面的数字，这样可以把在上一个循环多加数减掉。

时间复杂度：O(n)。空间复杂度：O(1)。

C++ 解法二：

```c++
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || symbolValues[s[i]] <= symbolValues[s[i - 1]])
                ans += symbolValues[s[i]];
            else 
                ans += symbolValues[s[i]] - 2 * symbolValues[s[i - 1]];
        }
        return ans;
    }
};
```



