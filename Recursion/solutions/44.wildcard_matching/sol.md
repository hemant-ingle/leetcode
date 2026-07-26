**Time Complexity:** *O(n × m),* **Space Complexity:** *O(n × m).*
```cpp
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];
        if(j==p.size()) return dp[i][j] = (i==s.size());
        if(i < s.size() && (s[i] == p[j] || p[j] =='?')) {
            return dp[i][j] = solve(i+1, j+1, s, p, dp);
        }
        if(p[j] == '*') {
            return dp[i][j] = solve(i, j+1, s, p, dp) || (i < s.size() && solve(i+1, j, s, p, dp));
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, p, dp);
    }
};
```