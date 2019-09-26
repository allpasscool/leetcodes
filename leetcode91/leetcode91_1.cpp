class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> dp(n + 1, 0); // dp[i] means the ways from s[i] to the end of s
        // dp[n] is empty '', which is one way
        if (n == 0)
            return 0;
        
        dp[n] = 1;
        if (s[n - 1] != '0')
            dp[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                    dp[i] += dp[i + 2];
            }
        }
        
        return dp[0];
    }
};

// Runtime: 4 ms, faster than 65.13% of C++ online submissions for Decode Ways.
// Memory Usage: 8.4 MB, less than 88.24% of C++ online submissions for Decode Ways.
// time complexity: O(n)
// space complexity: O(n)