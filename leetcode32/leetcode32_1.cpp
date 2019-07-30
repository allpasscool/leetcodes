class Solution {
public:
    int longestValidParentheses(string s) {
        int longest_valid = 0;
        if(s.length() == 0){
            return longest_valid;
        }
        
        int dp[s.length()] = {0};
        
        for(int i = 1; i < s.length(); i++){
            if(s[i] == ')'){
                if (s[i - 1] == '('){//....()
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (i - dp[i - 1] != 0 && s[i - dp[i - 1] - 1] == '('){//...((...))
                    dp[i] = dp[i-1] + ((i - dp[i-1]) >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;//...(())((...))
                }
                
                longest_valid = std::max(longest_valid, dp[i]);
            }
        }
        
        return longest_valid;
    }
};
// Runtime: 8 ms, faster than 65.42% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 8.9 MB, less than 95.24% of C++ online submissions for Longest Valid Parentheses.
// time complexity: O(n)
// space complexity: O(n)