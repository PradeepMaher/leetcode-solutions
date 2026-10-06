class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(mp.find(diff) != mp.end()){
                int j = mp[diff];
                return {i,j};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};