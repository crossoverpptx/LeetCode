#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string haystack = "sadbutsad", needle = "sad";
    Solution s;
    int ans = s.strStr(haystack, needle);
    cout << ans << endl;

    return 0;
}