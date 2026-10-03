class Solution {
    bool solve(int i, int j, string& s, string& p,
               vector<vector<int>>& dp) {

        // Both strings are completely matched
        if (i == 0 && j == 0)
            return true;

        // Pattern is finished but string remains
        if (j == 0)
            return false;

        // String is finished
        // Remaining pattern must contain only '*'
        if (i == 0) {
            for (int k = 0; k < j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Normal character or '?'
        if (p[j-1] == s[i-1] || p[j-1] == '?') {
            return dp[i][j] =
                solve(i-1, j-1, s, p, dp);
        }

        // '*'
        if (p[j-1] == '*') {
            return dp[i][j] =
                solve(i, j-1, s, p, dp) ||   // '*' matches zero
                solve(i-1, j, s, p, dp);      // '*' matches one/more
        }

        // Characters don't match
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, s, p, dp);
    }
};