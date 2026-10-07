class Solution {

    int solve(int i, int j, int[] cuts, int[][] dp) {

        if (i > j) return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = Integer.MAX_VALUE;

        for (int ind = i; ind <= j; ind++) {

            int cost = cuts[j + 1] - cuts[i - 1]
                    + solve(i, ind - 1, cuts, dp)
                    + solve(ind + 1, j, cuts, dp);

            mini = Math.min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    public int minCost(int n, int[] cuts) {

        int m = cuts.length;

        // Add boundaries
        int[] arr = new int[m + 2];

        arr[0] = 0;
        arr[m + 1] = n;

        for (int i = 0; i < m; i++) {
            arr[i + 1] = cuts[i];
        }

        Arrays.sort(arr);

        int[][] dp = new int[m + 1][m + 1];

        for (int i = 0; i <= m; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(1, m, arr, dp);
    }
}