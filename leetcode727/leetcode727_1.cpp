class Solution {
public:
    string minWindow(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        s1 = '#' + s1;
        s2 = '#' + s2;
        
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MAX / 2));
        
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }
        
        
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        
        int best = INT_MAX / 2;
        string ans = "";
        
        for (int i = 1; i <= n1; i++)
        {
            if (dp[i][n2] < best)
            {
                best = dp[i][n2];
                ans = s1.substr(i - dp[i][n2] + 1, dp[i][n2]);
            }
        }
        
        return ans;
    }
};


// Runtime: 472 ms, faster than 10.92% of C++ online submissions for Minimum Window Subsequence.
// Memory Usage: 90.3 MB, less than 15.63% of C++ online submissions for Minimum Window Subsequence.
// time complexity: O(MN) m is len of S, n is len of T
// space complexity: O(MN)
// https://github.com/wisdompeak/LeetCode/tree/master/Greedy/727.Minimum-Window-Subsequence
// https://www.youtube.com/watch?v=c8AgVpUtkwE&ab_channel=HuifengGuan


// class Solution {
// public:
//     string minWindow(string S, string T) 
//     {
//         int m = S.size();
//         int n = T.size();
//         S = "#" + S;
//         T = "#" + T;
//         auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        
//         for (int j = 1; j <= n; j++)
//             dp[0][j] = INT_MAX / 2;
//         for (int i = 0; i <= m; i++)
//             dp[i][0] = 0;
        
//         for (int i = 1; i <= m; i++)
//             for (int j = 1; j <= n; j++)
//             {
//                 if (S[i] == T[j])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = dp[i - 1][j] + 1;
//             }
        
//         int len  = INT_MAX / 2;
//         int pos;
//         for (int i = 1; i <= m; i++)
//         {
//             if (dp[i][n] < len)
//             {
//                 len = dp[i][n];
//                 pos = i;
//             }
//         }
        
//         if (len>=INT_MAX / 2)
//             return "";
//         else
//             return S.substr(pos - len + 1,len);
        
//     }
// };
