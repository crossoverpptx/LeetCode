#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

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

int main() {
	string str = "MCMXCIV";
	Solution s;
	int ans = s.romanToInt(str);
	cout << ans << endl;
	return 0;
}
