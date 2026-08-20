class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result, arr;

        result.push_back(nums[0]);
        arr.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (result.back() > arr.back()) {
                result.push_back(nums[i]);
            } else {
                arr.push_back(nums[i]);
            }
        }

        for (auto num : arr) {
            result.push_back(num);
        }

        return result;
    }
};