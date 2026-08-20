class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0 , maxlen = 0, zero = 0;

        while(r<n){
            if(nums[r] == 0){
                zero ++;
            }
            if(k < zero){
                if(nums[l] == 0){
                    zero --;
                }
                l++;
            }
            if(zero <= k) maxlen = max(maxlen, (r-l+1));
            r++;
        }
        return maxlen;
    }
};