class Solution {
    void solve(int i, vector<int>& nums, vector<int>& ans,
        vector<vector<int>>& res) {
        int n = nums.size();
            if (i == n) {
                if (ans.size() >= 2) {
                    res.push_back(ans);
                }
                return;
            }

            // TAKE
            if (ans.empty() || nums[i] >= ans.back()) {
                    ans.push_back(nums[i]);
                    solve(i + 1, nums, ans, res);
                    ans.pop_back();
            }

        // SKIP
        solve(i + 1, nums, ans, res);
    }
    public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;

        solve(0, nums, ans, res);

        set<vector<int>> unique(res.begin(), res.end()); 
        
        return vector<vector<int>>(unique.begin(), unique.end());
    }
};
