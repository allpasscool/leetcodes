class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), max_sum = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i-1] > 0) {
                nums[i] += nums[i - 1];
            }
            
            max_sum = max(nums[i], max_sum);
        }
        
        return max_sum;
    }
};
// Runtime: 8 ms, faster than 72.96% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.3 MB, less than 67.65% of C++ online submissions for Maximum Subarray.
// time complexity: O(n)
// space complexity: O(1)