class Solution {
    int solve(int i, int[] nums, int[] dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(i-1, nums, dp);
        int start = nums[i];

        return dp[i] = Math.max(pick, start); 
    }
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        int ans = nums[0];
        for(int i=0; i<n; i++){
            ans = Math.max(solve(i, nums, dp), ans);
        }

        return ans;
    }
}