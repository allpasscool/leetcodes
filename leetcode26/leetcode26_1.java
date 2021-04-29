class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        // count is for counting duplicate numbers
        int count = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1])
                count++;
            else
                nums[i-count] = nums[i];
        }
        
        return n - count;
    }
}

// // https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/11782/Share-my-clean-C%2B%2B-code
// Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 41 MB, less than 24.62% of Java online submissions for Remove Duplicates from Sorted Array.
// time complexity: O(n)
// space complexity: O(1)