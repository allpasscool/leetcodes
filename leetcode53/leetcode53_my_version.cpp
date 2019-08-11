class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int sum = nums[nums.size() - 1], max_sum = nums[nums.size() - 1];
        int head = nums.size() - 1, tail = nums.size() - 1;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            sum += nums[i];
            head = i;
            
            if (sum > max_sum) {
                max_sum = sum;
            }
            
            if (nums[i] >= sum || nums[tail] <= 0) {
                //remove tail, if sum become bigger
                while (tail > head && (sum - nums[tail] <= max_sum || nums[tail] <= 0)) {
                    sum -= nums[tail];
                    tail--;
                }
                if (sum > max_sum) {
                    max_sum = sum;
                }
            }
            
        }
        
        return max_sum;   
    }
};
// Runtime: 8 ms, faster than 72.96% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.2 MB, less than 95.10% of C++ online submissions for Maximum Subarray.
// time complexity: O(n)
// space complexity: O(1)