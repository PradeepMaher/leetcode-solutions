class Solution {
    bool solve(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(i == n-1) return true;
        if(dp[i] != -1) return dp[i];
        
        for(int ind= i+1; ind <= min(i+nums[i],n) ; ind++){
            if (solve(ind, nums, dp)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        return solve(0, nums, dp);
    }
};