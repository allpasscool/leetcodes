class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length;
        
        while (left < right) 
        {
            int middle = left + (right - left) / 2;//avoid overflow
            
            if (nums[middle] == target) 
            {
                return middle;
            }
            
            //the bottom half is sorted
            // 1 2 3 4 5 6 7
            // 3 4 5 6 7 1 2
            // 4 5 6 7 1 2 3
            if (nums[left] <= nums[middle]) 
            {
                // 1 2 3 4 5 6 7 target = 3
                // 3 4 5 6 7 1 2 target = 3
                // 4 5 6 7 1 2 3 target = 5
                if (nums[left] <= target && target < nums[middle])
                {
                    right = middle;
                } 
                // 1 2 3 4 5 6 7 target = 6
                // 3 4 5 6 7 1 2 target = 7 || 1
                // 4 5 6 7 1 2 3 target = 1
                else {
                    left = middle + 1;
                }
                
            } 
            // the upper half is sorted
            // 5 6 7 1 2 3 4
            // 6 7 1 2 3 4 5
            else { 
                // 5 6 7 1 2 3 4 target = 3
                // 6 7 1 2 3 4 5 target = 3
                if (nums[middle] < target && target <= nums[right - 1]) 
                {
                    left = middle + 1;
                } 
                // 5 6 7 1 2 3 4 target = 6
                // 6 7 1 2 3 4 5 target = 7
                else {
                    right = middle;
                }
                
            }
        }
        
        return -1;
    }
}

// Runtime: 1 ms, faster than 10.21% of Java online submissions for Search in Rotated Sorted Array.
// Memory Usage: 38.9 MB, less than 6.63% of Java online submissions for Search in Rotated Sorted Array.
// time complexity: O(log n)
// space complexity: O(1)
//  ref: https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14436/Revised-Binary-Search