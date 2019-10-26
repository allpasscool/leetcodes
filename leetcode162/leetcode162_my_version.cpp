class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;
        
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (mid == n - 1 && nums[mid] > nums[mid - 1])
                return mid;
            else if (mid == 0 && nums[mid] > nums[mid + 1])
                return mid;
            
            if (nums[mid + 1] < nums[mid] && nums[mid - 1] < nums[mid])
                return mid;
            else if (nums[mid + 1] > nums[mid])
                left = mid + 1;
            else if (nums[mid - 1] > nums[mid])
                right = mid;
        }
        
        return 0;
    }
};


// Runtime: 8 ms, faster than 50.99% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Find Peak Element.
// time complexity: O(log n)
// space complexity: O(1)