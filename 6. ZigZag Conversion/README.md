# ZigZag Conversion

**二维矩阵法**

设 n 为字符串 s 的长度，r = numRows。对于 r = 0（空字符串）或者 r = 1（只有一行）或者 r ≥ n（只有一列）的情况，答案与 s 相同，我们可以直接返回 s。对于其余情况，考虑创建一个二维矩阵，然后在矩阵上按 Z 字形填写字符串 s，最后逐行扫描矩阵中的非空字符，输出结果。

根据题意，当我们在矩阵上填写字符时，会先向下填写 r 个字符，然后向右上继续填写 r-2 个字符，最后回到第一行，因此 Z 字形变换的周期 t=r+r-2=2r-2，每个周期会占用矩阵上的 1+r-2=r-1 列。因此我们有 n/t 个周期（向上取整，即最后一个周期视作完整周期），乘上每个周期的列数，得到矩阵的列数 c=(n/t)*(r−1)。

创建一个 r 行 c 列的矩阵，然后遍历字符串 s 并按 Z 字形填写。设当前填写的位置为 (x,y)，即矩阵的 x 行 y 列。初始位置为 (x,y)=(0,0)，即矩阵左上角。若当前字符下标 i 满足 i%t < r-1，则向下移动，否则向右上移动。填写完成后，逐行扫描矩阵中的非空字符，输出结果。

时间复杂度：O(r⋅n)。空间复杂度：O(r⋅n)。

C++ 解法一：

```c++
class Solution {
public:
	string convert(string s, int numRows) {
		int n = s.length(), r = numRows;
		if (r == 0 || r == 1 || r >= n) {
			return s;
		}

		int t = 2 * r - 2; // 变换周期
		int c = (n + t - 1) / t * (r - 1); // 变换周期的个数向上取整 * 每个周期的列数 = 矩阵的列数
		vector<vector<char>> vec(r, vector<char>(c, 0)); //初始化一个r行c列的元素值全为0的二维矩阵
		for (int i = 0, x = 0, y = 0; i < n; ++i) {
			vec[x][y] = s[i];
			if (i % t < r - 1) {
				++x;
			}
			else {
				--x;
				++y;
			}
		}

		string res;
		for (auto row : vec) {
			for (char ch : row) {
				if (ch) {
					res += ch;
				}
			}
		}

		return res;
	}
};
```

**压缩矩阵空间**

方法一中的矩阵有大量的空间没有被使用，能否优化呢？

注意到每次往矩阵的某一行添加字符时，都会添加到该行上一个字符的右侧，且最后组成答案时只会用到每行的非空字符。因此我们可以将矩阵的每行初始化为一个空列表，每次向某一行添加字符时，添加到该行的列表末尾即可。

时间复杂度：O(n)。空间复杂度：O(n)。

C++ 解法二：

```c++
class Solution {
public:
	string convert(string s, int numRows) {
		int n = s.length(), r = numRows;
		if (r == 0 || r == 1 || r >= n) {
			return s;
		}

		int t = 2 * r - 2; // 变换周期
		vector<string> vec(r); //初始化一个r行的二维矩阵
		for (int i = 0, x = 0; i < n; ++i) {
			vec[x] += s[i];
			i% t < r - 1 ? ++x : --x;
		}

		string res;
		for (auto row : vec) {
			res += row;
		}

		return res;
	}
};
```

