class Solution {
    public int removeDuplicates(int[] nums) {
        // pos is for next non duplicates number
        int pos = 0;
        int n = nums.length;
        int i = 0;
        int ignore_count = 0;
        
        while (i < n) {
            int num = nums[i];
            swap(nums, pos, i);
            pos++;
            i++;
            
            while (i < n && nums[i] == num)
            {
                i++;
                ignore_count++;
            }
        }
        
        return n - ignore_count;
    }
    
    public void swap(int[] nums, int p1, int p2) {
        int tmp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = tmp;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 40.5 MB, less than 89.52% of Java online submissions for Remove Duplicates from Sorted Array.
// time complexity: O(n)
// space complexity: O(1)