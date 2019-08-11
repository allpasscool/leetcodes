class Solution {
public:
    int crossSum (vector<int>& nums, int left, int right, int p) {
        if (left == right) {
            return nums[left];
        }

        int left_subsum = INT_MIN;
        int curr_sum = 0;

        for (int i = p; i > left - 1; i--) {
            curr_sum += nums[i];
            left_subsum = max(left_subsum, curr_sum);
        }

        int right_subsum = INT_MIN;
        curr_sum = 0;

        for (int i = p + 1; i < right + 1; i++) {
            curr_sum += nums[i];
            right_subsum = max(right_subsum, curr_sum);
        }

        return left_subsum + right_subsum;
    }
    
    int helper (vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        
        int p = right % 2 == 0 ? (left + right / 2 - 1) : (left + right / 2);
        
        int left_sum = helper(nums, left, p);
        int right_sum = helper(nums, p + 1, right);
        int cross_sum = crossSum(nums, left, right, p);
        
        return max(max(left_sum, right_sum), cross_sum);
    }
    
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
// stack overflow
// time complexity: O(n logn) (1 * N) + (2 *(N/2)) + (4 * (N/4)) ... (N * 1), total log N items, N log N
// space comlexity: O(log N) to keep the recursion track