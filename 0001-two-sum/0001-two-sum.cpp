class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<pair<int, int>> arr;

        // Store value + original index
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int l = 0;
        int r = n - 1;

        while (l < r) {

            int sum = arr[l].first + arr[r].first;

            if (sum == target) {
                return {arr[l].second, arr[r].second};
            }

            if (sum < target) {
                l++;
            } else {
                r--;
            }
        }

        return {};
    }
};