class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long>> f(n + 1, vector<long> (m + 1, INT_MAX)); // f[i][j] means to i position and split to j parts
        vector<long> sub(n + 1, 0);
        
        // sum to pos i from 1 to n
        for (int i = 0; i < n; ++i) {
            sub[i + 1] = sub[i] + nums[i];
        }
        
        f[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k < i; ++k) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        
        return f[n][m];
    }
};

// Runtime: 160 ms, faster than 12.87% of C++ online submissions for Split Array Largest Sum.
// Memory Usage: 9.5 MB, less than 20.00% of C++ online submissions for Split Array Largest Sum.
// time complexity: O(n^2 * m)
// space complexity: O(n * m)