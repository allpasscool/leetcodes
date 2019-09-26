class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        // vector<int> dp(n + 1, 0); // dp[i] means the ways from s[i] to the end of s
        // dp[n] is empty '', which is one way
        if (n == 0)
            return 0;
        int dp_ip2 = 0, dp_ip1 = 0; // dp[i + 2], dp[i + 1]
        int current = 0;
        
        // dp[n] = 1;
        dp_ip2 = 1;
        
        if (s[n - 1] != '0')
            dp_ip1 = 1; // dp[n - 1] = 1;
        current = dp_ip1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0')
                current = 0; // dp[i] = 0;
            else {
                current = dp_ip1; // dp[i] = dp[i + 1];
                
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                    current += dp_ip2; // dp[i] += dp[i + 2];
            }
            dp_ip2 = dp_ip1;
            dp_ip1 = current;
        }
        
        // return dp[0];
        return current;
    }
};

// Runtime: 4 ms, faster than 65.13% of C++ online submissions for Decode Ways.
// Memory Usage: 8.5 MB, less than 82.35% of C++ online submissions for Decode Ways.
// time complexity: O(n)
// space complexity: O(1)