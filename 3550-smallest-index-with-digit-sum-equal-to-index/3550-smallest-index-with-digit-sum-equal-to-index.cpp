class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int mini = 1e9;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }

            if(sum == i) {
                mini = min(mini, i);
            }
        }

        return mini == 1e9 ? -1 : mini;
    }
};