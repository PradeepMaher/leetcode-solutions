class Solution {
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int take=0, nottake=0, maxi =INT_MIN;
        if(buy){
            nottake = 0 + solve(i+1, 1, prices, dp);
            take = -prices[i] + solve(i+1, 0, prices, dp);
            maxi = max(take, nottake);
        }else{
            nottake = 0 + solve(i+1, 0, prices, dp);
            take = prices[i] + solve(i+2, 1, prices, dp);
            maxi = max(take, nottake);
        }

        return dp[i][buy] = maxi;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(0, 1, prices,dp);
    }
};