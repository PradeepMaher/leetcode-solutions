class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2) return false;

        int target = sum/2;

        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        return solve(n - 1, target, nums, dp);
    }

    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return target == nums[0];
        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = solve(i-1, target, nums, dp);
        bool take = false;
        if(target >= nums[i]) take = solve(i-1, target-nums[i], nums, dp);

        return dp[i][target] = take||notTake;
    }
};