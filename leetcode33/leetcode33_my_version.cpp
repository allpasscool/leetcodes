class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        } else if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        } 
        
        int nums_size = nums.size();
        int left = 0, right = nums_size - 1;
        
        while (left < right) {
            if (nums[left] == target) {
                return left;
                
            } else if (nums[right] == target) {
                return right;
                
            } else {
                int middle = left + (right - left) / 2;
                
                if (middle == left || middle == right) {
                    break;
                }
                
                if (nums[middle] == target) {
                    return middle;
                    
                } else if (nums[middle] > nums[left] && nums[middle] > nums[right]){//2 3 4 5 0 1
                    if (target > nums[left] && target < nums[middle]) {
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                    
                } else if (nums[middle] > nums[left] && nums[middle] < nums[right]) {
                    
                    if (target < nums[middle]) {
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                    
                } else if (nums[middle] < nums[left] && nums[middle] > nums[right]) {
                    //impossible
                    return -2;//error
                    
                } else if (nums[middle] < nums[left] && nums[middle] < nums[right]){
                    
                    if (target < nums[right] && target > nums[middle]) {
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
            }
        }
        
        return -1;
    }
};
// Runtime: 4 ms, faster than 82.19% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 8.8 MB, less than 63.12% of C++ online submissions for Search in Rotated Sorted Array.
// time complexity: O(log n)
// space complexity: O(1)