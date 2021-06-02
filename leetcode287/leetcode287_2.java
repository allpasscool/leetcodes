class Solution {
    public int findDuplicate(int[] nums) {
        // Find the intersection point of the two runners.
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find the "entrance" to the cycle.
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
}

// Runtime: 6 ms, faster than 32.58% of Java online submissions for Find the
// Duplicate Number.
// Memory Usage: 73.7 MB, less than 5.06% of Java online submissions for Find
// the Duplicate Number.
// time complexity: O(n)
// space complexity: O(1)
// reference: happy number leetcode 202