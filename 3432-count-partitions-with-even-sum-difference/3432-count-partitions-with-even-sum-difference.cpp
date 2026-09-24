class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int diff = 0, count = 0;

        vector<int> prefix(n, 0), suffix(n, 0);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        for (int j = n - 2; j >= 0; j--) {
            suffix[j] = nums[j] + suffix[j + 1];
        }

        // Partition after index i
        for (int i = 0; i < n - 1; i++) {
            diff = prefix[i] - suffix[i + 1];

            if (diff % 2 == 0)
                count++;
        }

        return count;
    }
};