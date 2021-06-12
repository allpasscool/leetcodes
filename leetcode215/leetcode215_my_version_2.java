class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;

        return nums[n - k];
    }
}

// Runtime: 1 ms, faster than 97.97% of Java online submissions for Kth Largest
// Element in an Array.
// Memory Usage: 39.4 MB, less than 47.81% of Java online submissions for Kth
// Largest Element in an Array.
// tiem complexity: O(n log n)
// space complexity: O(1)