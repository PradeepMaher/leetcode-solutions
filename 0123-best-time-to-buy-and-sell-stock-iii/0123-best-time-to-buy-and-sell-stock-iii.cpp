class Solution {
    int solve(int i, int trans, vector<int> &prices, vector<vector<int>> &dp){
        if( i == prices.size() || trans == 4) return 0;
        if(dp[i][trans] != -1 ) return dp[i][trans];

        if(trans % 2 == 0 ){
            return dp[i][trans] = max( -prices[i] + solve(i+1,trans+1, prices, dp), solve(i+1,trans, prices, dp) );
        }
        return dp[i][trans] = max(prices[i] + solve(i+1,trans+1, prices, dp), solve(i+1,trans, prices, dp) );
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,
                    vector<int>(4,-1));

        return solve(0, 0, prices, dp);
    }
};