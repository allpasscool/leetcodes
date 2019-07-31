class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;
        
        if (nums.size() == 0 || nums[0] >= target) {
            return 0;
        } else if (nums[right] < target) {
            return right + 1;
        } else if (nums[right] == target) {
            return right;
        }
        
        while (left < right) {
            middle = left + (right - left) / 2;
            
            if (nums[left] == target) {
                return left;
            } else if (nums[right] == target) {
                return right;
            } else if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            }
            
        }
        
        if (nums[left] < target) {
            return left + 1;
        } else {
            return left;
        }
    }
};
// Runtime: 4 ms, faster than 98.77% of C++ online submissions for Search Insert Position.
// Memory Usage: 8.9 MB, less than 73.82% of C++ online submissions for Search Insert Position.
// time complexity: O(log n)
// space complexity: O(1)