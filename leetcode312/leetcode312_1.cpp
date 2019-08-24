class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // reframe the problem
        int n = nums.size() + 2;
        // vector<int> new_nums(n, 0);
        
        // for (int i = 0; i < nums.size(); i++) {
        //     new_nums[i + 1] = nums[i];
        // }
        
        // new_nums[0] = new_nums[n - 1] = 1;
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        // cache the results of dp
        vector<vector<int>> memo (n, vector<int> (n, 0));
        
        // find the maximum number of coins obtained from adding all balloons 
        // from (0, len(nums) - 1)
        // return dp(memo, new_nums, 0, n - 1);
        return dp(memo, nums, 0, n - 1);
    }
    
private:
    int dp(vector<vector<int>>& memo, vector<int>& nums, int left, int right) {
        // no more balloons can be added
        if (left + 1 == right) {
            return 0;
        }
        
        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }
        
        // add each balloon on the interval and return the maximum score
        int ans = 0;
        for (int i = left + 1; i < right; i++) {
            ans = max(ans, nums[left] * nums[i] * nums[right]
                + dp(memo, nums, left, i) + dp(memo, nums, i, right));
        }
        // add to the cache
        memo[left][right] = ans;
        return ans;
    }
};
// Runtime: 28 ms, faster than 26.67% of C++ online submissions for Burst Balloons.
// Memory Usage: 9.5 MB, less than 30.00% of C++ online submissions for Burst Balloons.
// time complexity: O(n^3)
// space complexity: O(n^2)