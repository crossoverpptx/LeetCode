# Reverse Integer

**数学法**

一开始还想着分正负数处理，但是看了官方的解答发现不用特意处理正负号，这道题唯一需要处理的就是溢出问题。由于 int 型的数值范围是 -2147483648～2147483647，所以当 res 的绝对值大于 214748364 就可以判断最后结果超过 int 范围了，那么要不要处理等于呢？不用，因为输入的整数是 int 范围内的，所以当输入整数是最高位时，最后一位数字肯定是小于等于 2 的，不用 check。

时间复杂度：O(log|x|)。空间复杂度：O(1)。

C++ 解法一：

```c++
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
```

**数学法 - long 保存计算结果值**

也可以用 long 型变量保存计算结果，最后返回的时候判断是否在 int 返回内，但其实题目中说了只能存整型的变量，所以这种方法就只能当个思路扩展了，但实际发现 OJ 也通过了。

时间复杂度：O(log|x|)。空间复杂度：O(1)。

C++ 解法二：

```c++
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};
```

