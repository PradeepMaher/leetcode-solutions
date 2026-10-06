class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        // Prefix product
        int prev = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prev;
            prev *= nums[i];
        }

        // Suffix product
        prev = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= prev;
            prev *= nums[i];
        }

        return ans;
    }
}