# String to Integer (atoi)

**朴素法**

OJ 没通过，最后执行的输入是"+-12"，但是"+-12"我本地是通过的，没搞懂。

时间复杂度：O(n)。空间复杂度：O(1)。

C++ 解法一：

```c++
class Solution {
public:
	int myAtoi(string s) {
		int l = s.length(), flag = 1;
		long res = 0;

		for (int i = 0; i < l; ++i) {
			if (s[i] == ' ') {
				continue;
			}
			else if(s[i] == '+') {
				if(flag == -1) // 判断例如"-+12"的情况
					flag = -1;
				else
					flag = 1;
				continue;
			}
			else if (s[i] == '-') {
				flag = -1;
				continue;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				res = res * 10 + s[i] - '0';
			}
			else {
				break; // 若数字后有字符，结束
			}
		}
		res *= flag;

		if (res > INT_MAX || res < INT_MIN) {
			return (flag == 1) ? INT_MAX : INT_MIN;
		}
		else {
			return res;
		}
	}
};

```

**朴素法 - 改进**

这种方法没有判断例如"-+12"这种情况，但是 OJ 通过了，让我很是疑惑。

时间复杂度：O(n)。空间复杂度：O(1)。

C++ 解法二：

```c++
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0; // 判断空字符串
        int sign = 1, base = 0, i = 0, n = str.size();
        while (i < n && str[i] == ' ') ++i; // 判断前导空格
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i++] == '+') ? 1 : -1; // 没有判断例如"-+12"这种情况
        }
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
```

