class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int profit = 0, mini = prices[0];
        int i = 0;
        while( i < n ){
            int cost = prices[i] - mini;
            profit = Math.max(profit, cost);
            mini = Math.min(mini, prices[i]);
            i++;
        }

        return profit;
    }
}