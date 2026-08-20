class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
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
            if(zero <= k) maxlen = Math.max(maxlen, (r-l+1));
            r++;
        }
        return maxlen;
    }
}