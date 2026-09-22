class Solution {
public:

    int solve(int i, int j1, int j2,
              vector<vector<int>>& a,
              vector<vector<vector<int>>>& dp) {

        // Out of bounds
        if (j1 < 0 || j1 >= a[0].size() ||
            j2 < 0 || j2 >= a[0].size()) {
            return -1e9;
        }

        // Last row
        if (i == a.size() - 1) {
            if (j1 == j2)
                return a[i][j1];
            else
                return a[i][j1] + a[i][j2];
        }

        // Already calculated
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int cherries;

        if (j1 == j2)
            cherries = a[i][j1];
        else
            cherries = a[i][j1] + a[i][j2];

        int maxi = -1e9;

        // 9 possible combinations
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {

                int value = cherries +
                    solve(i + 1,
                          j1 + dj1,
                          j2 + dj2,
                          a,
                          dp);

                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }


    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(m, -1)
            )
        );

        return solve(0, 0, m - 1, grid, dp);
    }
};