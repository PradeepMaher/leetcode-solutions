class Solution {
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i == 0){
            return target%nums[0] == 0 ? (target/nums[0]) : INT_MAX;
        }

        if(dp[i][target] != -1) return dp[i][target];

        int nottake = solve(i-1, target, nums, dp);
        int take = INT_MAX;
        if(nums[i] <= target){
            int ans = solve(i, target-nums[i], nums, dp);

            if(ans != INT_MAX)
                take = 1 + ans;
        }

        return dp[i][target] = min(nottake, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = solve(n-1, amount, coins, dp);

        if(ans == INT_MAX)
            return -1;

        return ans ;
    }
};