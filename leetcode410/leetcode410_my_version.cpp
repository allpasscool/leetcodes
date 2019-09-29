class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 0 || m == 0)
            return 0;
        
        vector<vector<long long>> dp_sum(n, vector<long long> (n, 0)); // dp[i][j] from pos i to pos j, and their sum value
        
        // all sum from i to j
        // time complexity: O(n^2)
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                dp_sum[i][j] = i == j ? nums[i] : (dp_sum[i][j - 1] + nums[j]);
            }
        }
        
        // dp_min_sum[i][j] can besplit to i part and from begin to pos j and 
        vector<vector<long long>> dp_min_sum(m, vector<long long> (n, INT_MAX));
        
        // only one part
        for (int i = 0; i < n; ++i) {
            dp_min_sum[0][i] = dp_sum[0][i];
        }
        
        // number of split part
        for (int i = 1; i < m; ++i) {
            // where the last part end
            for (int k = i; k < n; ++k) {
                // where the last part start to end
                // j = i + 1 because, each part has at least one element
                for (int j = i; j <= k; ++j) {
                    long long from_j_to_k = dp_sum[j][k];
                    long long this_way_to_split = max(dp_min_sum[i - 1][j - 1]
                                                , from_j_to_k);
                    dp_min_sum[i][k] = min(dp_min_sum[i][k], this_way_to_split);
                }
            }
        }
        
        return dp_min_sum[m - 1][n - 1];
    }
};

// Runtime: 172 ms, faster than 9.78% of C++ online submissions for Split Array Largest Sum.
// Memory Usage: 24.6 MB, less than 10.00% of C++ online submissions for Split Array Largest
// time complexity: O(m * n * n)
// space complexity: O(m*n + n*n)