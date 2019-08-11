class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum = nums[0], max_sum = nums[0];
        
        for (int i = 1; i < n; i++) {
            curr_sum = max(nums[i], curr_sum + nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        
        return max_sum;
    }
};
// Runtime: 8 ms, faster than 72.96% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.3 MB, less than 67.65% of C++ online submissions for Maximum Subarray.
// time complexity: O(N)
// space complexity: O(1)