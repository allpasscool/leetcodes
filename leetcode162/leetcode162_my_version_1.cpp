class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1 || nums[0] > nums[1])
            return 0;
        
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        
        if (nums[n - 1] > nums[n - 2])
            return n -1;
        
        return -1;
    }
};


// Runtime: 8 ms, faster than 50.99% of C++ online submissions for Find Peak Element.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Find Peak Element.
// time complexity: O(n)
// space complexity: O(1)