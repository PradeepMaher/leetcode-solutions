class Solution {
    int solve(int i, int target, vector<int>& nums,
              vector<vector<int>>& dp) {

        if (i == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;

            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = solve(i - 1, target, nums, dp);

        int take = 0;
        if (nums[i] <= target)
            take = solve(i - 1, target - nums[i], nums, dp);

        return dp[i][target] = take + notTake;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        // Impossible cases
        if (abs(target) > sum)
            return 0;

        if ((sum + target) % 2 != 0)
            return 0;

        int subsetTarget = (sum + target) / 2;

        vector<vector<int>> dp(
            n,
            vector<int>(subsetTarget + 1, -1)
        );

        return solve(n - 1, subsetTarget, nums, dp);
    }
};