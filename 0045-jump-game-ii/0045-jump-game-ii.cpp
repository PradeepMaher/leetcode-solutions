class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i >= n-1 ) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int ind = i+1; ind<= min(i+ nums[i], n-1); ind++){
            int nextJump = solve(ind, nums, dp);

            if (nextJump != INT_MAX) {
                mini = min(mini, 1 + nextJump);
            }
        }

        return dp[i] = mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,-1);
        return solve(0, nums, dp);
    }
};