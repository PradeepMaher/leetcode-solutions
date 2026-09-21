class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();

        vector<int> prev(m,0);  
        for(int j=0; j<m; j++){
            prev[j] = triangle[n-1][j];
        }

        for(int i = n-2; i>=0; i--){
            vector<int> curr(m,0);
            for(int j = i; j>=0; j--){
                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];

                curr[j] = min(d,dg);
            }
            prev = curr;
        }

        return prev[0];
    }
};