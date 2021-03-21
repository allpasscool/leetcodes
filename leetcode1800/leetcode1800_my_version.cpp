class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]){
                cur_sum = nums[i];
            }
            else {
                cur_sum += nums[i];
            }
            
            max_sum = max(max_sum, cur_sum);
        }
        
        return max_sum;
    }
};

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Maximum Ascending Subarray Sum.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Maximum Ascending Subarray Sum.
// time complexity: O(n)
// space complexity: O(n)