class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i = 1; i < n; i++) {
            temp1.push_back(nums[i]);
        }

        for(int i = 0; i < n - 1; i++) {
            temp2.push_back(nums[i]);
        }

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = solve(n - 2, temp1, dp1);
        int case2 = solve(n - 2, temp2, dp2);

        return max(case1, case2);
    }

    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i < 0) return 0;

        if(i == 0) return nums[0];

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(i - 2, nums, dp);
        int notpick = solve(i - 1, nums, dp);

        return dp[i] = max(pick, notpick);
    }
};