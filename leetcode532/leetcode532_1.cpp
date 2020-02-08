class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // sums[i] = previous i elemnts sum
        vector<int> sums(nums.size() + 1);
        
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        
        for (int start = 0; start < nums.size(); ++start) {
            for (int end = start + 1; end < nums.size(); ++end) {
                int diff = sums[end] - sums[start] + nums[start]; // at least two nums
                
                if (diff == k || (k != 0 && diff % k == 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


// Runtime: 44 ms, faster than 32.66% of C++ online submissions for Continuous Subarray Sum.
// Memory Usage: 11.5 MB, less than 75.00% of C++ online submissions for Continuous Subarray Sum.
// time complexity: O(n^2)
// space complexity: O(n)