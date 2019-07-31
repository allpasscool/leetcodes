class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int middle = left + (right - left) / 2;//avoid overflow
            
            if (nums[middle] == target) {
                return middle;
            }
            
            //the bottom half is sorted
            if (nums[left] <= nums[middle]) {
                
                if (nums[left] <= target && target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
                
            } else { //the upper half is sorted
                
                if (nums[middle] < target && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
                
            }
        }
        
        return -1;
    }
};
// Runtime: 4 ms, faster than 82.19% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 8.8 MB, less than 41.48% of C++ online submissions for Search in Rotated Sorted Array.
// time complexity: O(log n)
// space complexity: O(1)