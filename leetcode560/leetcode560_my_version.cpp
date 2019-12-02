class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                
                if (sum == k)
                    ++ans;
            }
        }
        
        return ans;
    }
};


// Runtime: 488 ms, faster than 18.32% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 10 MB, less than 98.67% of C++ online submissions for Subarray Sum Equals K.
// time complexity: O(n^2)
// space complexity: O(1)