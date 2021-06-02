class Solution {
    // 1 2 3 3 4 5 6 ans = 3
    // 1 2 2 2 2 2 2 ans = 2
    // 1 1 2 3 4 5 6 ans = 1
    // 1 2 3 4 5 6 6 ans = 6
    public int findDuplicate(int[] nums) {
        int n = nums.length - 1;
        int left = 1, right = nums.length;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            if (count <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
}

// Runtime: 23 ms, faster than 17.25% of Java online submissions for Find the
// Duplicate Number.
// Memory Usage: 57.1 MB, less than 9.49% of Java online submissions for Find
// the Duplicate Number.
// time complexity: O(n log n)
// space complexity: O(1)
// https://leetcode.com/problems/find-the-duplicate-number/discuss/72844/Two-Solutions-(with-explanation)%3A-O(nlog(n))-and-O(n)-time-O(1)-space-without-changing-the-input-array