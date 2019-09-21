class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        
        return nums[n - k];
    }
};

// Runtime: 12 ms, faster than 77.31% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Kth Largest Element in an Array.
// time complexity: O(nlogn)
// space complexity: O(1)