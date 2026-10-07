/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                // mid is bad, so answer is mid or before it
                high = mid;
            } else {
                // mid is good, so answer must be after mid
                low = mid + 1;
            }
        }

        return low;
    }
}