class Solution {
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        if (nums[i] > nums[i - 1]) {
            return dp[i] = 1 + solve(i - 1, nums, dp);
        }

        return dp[i] = 1;
    }

public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, nums, dp));
        }

        return ans;
    }
};