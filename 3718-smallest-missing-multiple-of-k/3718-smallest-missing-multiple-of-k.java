import java.util.*;

class Solution {
    public int missingMultiple(int[] nums, int k) {
        Arrays.sort(nums);

        int expected = k;

        for (int num : nums) {
            if (num == expected) {
                expected += k;
            }
        }

        return expected;
    }
}