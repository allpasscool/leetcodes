class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap; // accumulate_sum, # of this count
        hashmap[0] = 1; // means that if we want to find accumulate sum == 0, sum now is k
        
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            
            if (hashmap[sum - k] > 0) {
                ans += hashmap[sum - k];
            }
            
            ++hashmap[sum];
        }
        
        return ans;
    }
};


// Runtime: 44 ms, faster than 52.12% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 18.1 MB, less than 20.00% of C++ online submissions for Subarray Sum Equals K.
// time complexity: O(n)
// space complexity: O(n)