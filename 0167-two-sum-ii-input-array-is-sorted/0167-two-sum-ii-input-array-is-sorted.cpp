class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r = n-1;
        vector<int> ans;
        while( r < n ){
            int sum = nums[l] + nums[r];
            if(sum == target){
                break;
            }else if( sum < target){
                l++;
            }else{
                r--;
            }
        }

        ans.push_back(l+1);
        ans.push_back(r+1);
        return ans;
    }
};