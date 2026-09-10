class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bi=0; bi<=31; bi++){
            int count = 0;
            for(int i=0; i<n; i++){
                if(nums[i] & (1 << bi)){
                    count++;
                }
            }
            if(count%3 == 1) ans = ans | (1 << bi);
        }
         return ans;
    }
};