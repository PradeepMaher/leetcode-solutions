class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            set<int> st;

            for (int j = i; j < n; j++) {
                // nums[j] ko set mein insert kar
                st.insert(nums[j]);
                // distinct elements ki count nikal
                int s = st.size();
                // us count ka square sum mein add kar
                sum += s*s;
            }
        }

        return sum;
    }
};