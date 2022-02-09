# Longest Substring Without Repeating Characters

首先想到的方法是：将s的首元素存入一个子数组subs，遍历s，若s中元素和此时subs中所有元素都不相等，则将s中该元素存入subs中；若出现相等，则说明此时subs就是当前最长子串，将长度存入max，并清空subs，同时从s的+1位置开始重新计算新的最长子串，若新的最长子串大于max则重置max，否则继续+1重复。该方法过于复杂，不列出详细解法。

该题可以通过滑动窗口的思想来解决。定义一个哈希表，用来存放窗口中的值，定义一个左边界和右边界，指向字符串起始位置。当右边界小于字符串长度，说明未遍历结束，进入循环。当右边界小于字符串长度并且其指向的字符对应值为0（字符在哈希表中初始值为0），将该字符放入窗口并将值置为1，右边界向右移动。当右边界所指字符在窗口中已有，则先记录此时最长子串长度，然后缩小窗口，直到窗口中没有重复字符。重复循环，直到遍历完字符串。

C++ 解法一：

```c++
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
```

下面这种解法更加简单，使用了HashSet，把出现过的字符都放入HashSet中，遇到HashSet中没有的字符就加入HashSet中并更新结果res，如果遇到重复的，则从左边开始删字符，直到删到重复的字符停止。为什么不使用set呢？因为HashSet是无序的，而set会自动排序，很明显HashSet更符合题意，虽然实践中发现set也能通过。

C++ 解法二：

```c++
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
```

