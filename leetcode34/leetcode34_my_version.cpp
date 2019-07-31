class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, interval, middle_index = -1, middle;
        vector<int> output(2, -1);
        
        if(nums.size() == 0) {
            return output;
        }
        
        if (nums[left] == target && nums[right] == target) {
            output[0] = left;
            output[1] = right;
            
            return output;
        }
        
        //locate target, ..***7***..
        while (left <= right) {
            interval = (right - left) / 2;
            middle = left + interval;
            
            if (nums[left] == target) {
                output[0] = left;
                middle_index = left;
                interval *= 2;
                
                break;
            } else if (nums[right] == target) {
                output[1] = right;
                middle_index = right;
                interval *= 2;
                
                break;
            } else if (nums[middle] == target) {
                middle_index = middle;
                
                break;
            } else if (nums[middle] > target) {
                right = middle - 1;
                
            } else if (nums[middle] < target) {
                left = middle + 1;
            }
        }
        
        //not ofund
        if (middle_index == -1) {
            return output;
        }
        
        //find start
        left = middle_index - interval;
        right = middle_index;
        if (output[0] == -1) {
            output[0] = middle_index;
            int tmp_interval;
            
            while (left <= right) {
                tmp_interval = (right - left) / 2;
                middle = left + tmp_interval;
                
                if (nums[left] == target) {
                    output[0] = left;
                    break;
                } else if (nums[middle] == target) {
                    output[0] = middle;
                    right = middle - 1;
                } else if (nums[right] == target) {
                    output[0] = right;
                    left = middle + 1;
                } else if (nums[middle] < target) {
                    left = middle + 1;
                }
            }
        }
        
        left = middle_index;
        right = middle_index + interval;
        if (output[1] == -1) {
            output[1] = middle_index;
            int tmp_interval;
            
            while (left <= right) {
                tmp_interval = (right - left) / 2;
                middle = left + tmp_interval;
                
                if (nums[right] == target) {
                    output[1] = right;
                    break;
                } else if (nums[middle] == target) {
                    output[1] = middle;
                    left = middle + 1;
                } else if (nums[left] == target) {
                    output[1] = left;
                    right = middle - 1;
                } else if (nums[middle] > target) {
                    left = middle + 1;
                }
            }
        }
        
        return output;
    }
};
// Runtime: 8 ms, faster than 86.80% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 10.3 MB, less than 75.94% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// time complexity: O(3 log n)
// space complexity: O(1)