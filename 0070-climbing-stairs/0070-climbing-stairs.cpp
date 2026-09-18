class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        return solve(n, dp);
    }

    int solve(int i, vector<int>& dp){
        if(i <= 1) return 1;

        if(dp[i] != -1) return dp[i];

        int left = solve(i-1, dp);
        int right = solve(i-2, dp);

        return dp[i] = left + right;
    }
};