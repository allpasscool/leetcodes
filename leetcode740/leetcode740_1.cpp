class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        
        return max(take, skip);
    }
};

// Runtime: 8 ms, faster than 78.46% of C++ online submissions for Delete and Earn.
// Memory Usage: 11 MB, less than 25.00% of C++ online submissions for Delete and Earn.
// time complexity: O(N + W), W is the range of allowable value of nums[i]
// space complexity: O(W)