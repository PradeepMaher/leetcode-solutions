class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0, even = 0;
        for(int num : nums1){
            if(num% 2 == 1)
                odd++;
            else        
                even++;
        }
        sort(nums1.begin(), nums1.end());
        if(nums1[0]%2 == 0 && even != n){
            return false;
        }
        return true;
    }
};