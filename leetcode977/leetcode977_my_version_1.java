class Solution {
    public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] *= nums[i];
        }
        
        Arrays.sort(nums);
        
        return nums;
    }
}

// Runtime: 3 ms, faster than 29.34% of Java online submissions for Squares of a Sorted Array.
// Memory Usage: 41 MB, less than 21.16% of Java online submissions for Squares of a Sorted Array.
// time complexity: O(n log n)
// space complexity: O(1)