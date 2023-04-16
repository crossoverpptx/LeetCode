# 28. Implement strStr()（找出字符串中第一个匹配项的下标）

## 方法1：三指针法（暴力法）

### 思路与算法

定义两个指针p、q，分别指向 haystack 和 needle 的起始位置。开始遍历，如果 haystack 中开始匹配 needle，则标记此时 haystack 的位置为 p1，继续遍历。如果匹配中断，则指针 p 回到 p1 位置，继续遍历。如果遍历完haystack 还未完全匹配，则匹配失败；如果匹配成功，则返回p - j，即p1。

### 复杂度分析

- 时间复杂度：O(m*n)，其中 m 是字符串 haystack 的长度，n 是字符串 needle 的长度。最坏情况下我们需要将字符串 needle 与字符串 haystack 的所有长度为 n 的子串均匹配一次。
- 空间复杂度：O(1)。我们只需要常数的空间保存若干变量。

### C++ 解法一

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = haystack.size(), j = needle.size();
        int p = 0, p1 = 0, q = 0;

        while(p < i && q < j) {
            if(haystack[p] == needle[q]) {
                if(q == 0)
                    p1 = p; // 标记haystack中匹配needle的起始位置
                p++;
                q++;
            }else {
                if(p >= 1 && q >= 1 && (haystack[p - 1] == needle[q - 1])) {
                    p = p1 + 1; // 匹配失败，p 回到 p1+1 位置
                    q = 0;
                }
                else {
                    p++;
                    q = 0;
                }
            }
        }
        if(p == i && q < j)
            return -1;
        else
            return p - j;
    }
};
```

C++ 解法一的另一种实现：

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};
```



## 方法2：KMP算法

### 思路与算法

### 复杂度分析

### C++ 解法二

