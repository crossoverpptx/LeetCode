#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesisDFS(0, 0, n, "");
        return ans;
    }

    void generateParenthesisDFS(int lc, int rc, int n, string seq) {
        if (lc == n && rc == n) {
            ans.push_back(seq);
            return;
        }
        if (lc < n)
            generateParenthesisDFS(lc + 1, rc, n, seq + '(');
        if (rc < n && lc > rc)
            generateParenthesisDFS(lc, rc + 1, n, seq + ')');
    }
};

int main() {
    int n = 3;

    Solution s;
    vector<string> res;
    res = s.generateParenthesis(n);

    cout << "[";
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
        if(it == res.end() - 1)
            cout << "\"" << *it << "\"";
        else
            cout << "\"" << *it << "\",";
    }
    cout << "]";

    return 0;
}
