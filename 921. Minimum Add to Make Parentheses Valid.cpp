#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int ans = 0;
        for (auto &c : s) {
            if (c == '(') {
                stk.push(c);
            } else if (c == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    ans++;
                }
            }
        }
        ans += stk.size();
        return ans;
    }
};

// passed less than 50% testcases, took help from chatgpt