class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1, vector<string>());
        
        dp[0] = vector<string>{""};
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                for(string &left: dp[j]){
                    for(string &right: dp[i-j-1]){
                        string tmp = '(' + left + ')' + right;
                        dp[i].push_back(tmp);
                    }
                }
            }
        }
        
        return dp[n];
    }
};
// Runtime: 4 ms, faster than 90.66% of C++ online submissions for Generate Parentheses.
// Memory Usage: 10.1 MB, less than 95.16% of C++ online submissions for Generate Parentheses.
// time complexity: O(2^n)
// space complexity: O(2^n)