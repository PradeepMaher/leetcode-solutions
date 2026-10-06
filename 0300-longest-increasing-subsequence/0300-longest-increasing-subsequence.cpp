class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

    for (int num : nums) {
        int left = 0;
        int right = tails.size();

        // lower_bound: first element >= num
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (tails[mid] >= num)
                right = mid;
            else
                left = mid + 1;
        }

        if (left == tails.size())
            tails.push_back(num);
        else
            tails[left] = num;
    }

    return tails.size();
    }
};