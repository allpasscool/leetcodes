/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

    public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1, right = n;
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid) == true)
            {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
}

// Runtime: 12 ms, faster than 97.85% of Java online submissions for First Bad Version.
// Memory Usage: 35.8 MB, less than 36.96% of Java online submissions for First Bad Version.
// time complexity: O(log n)
// space complexity: O(1)