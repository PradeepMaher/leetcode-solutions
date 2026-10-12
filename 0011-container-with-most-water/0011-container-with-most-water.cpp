class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxCap = INT_MIN;
        int l = 0, r = n-1;
        while(l <=r){
            int h = min(height[l],height[r]);
            int len = r-l;
            int cap = h * len;
            maxCap = max(maxCap, cap);
            if(height[l] <= height[r]){
                l++;
            }else{
                r--;
            }
        }

        return maxCap;
    }
};