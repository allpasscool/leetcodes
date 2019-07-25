class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backtrack(output, "", 0, 0, n);
        return output;
    }
    
    void backtrack(vector<string> &ans, string cur, int open, int close, int max){
        if(cur.length() == max * 2){
            ans.push_back(cur);
            return;
        }
        
        if(open < max){
            backtrack(ans, cur+'(', open+1, close, max);
        }
        
        if(close < open){
            backtrack(ans, cur+')', open, close+1, max);
        }
    }
};
// Runtime: 16 ms, faster than 13.93% of C++ online submissions for Generate Parentheses.
// Memory Usage: 17.1 MB, less than 65.74% of C++ online submissions for Generate Parentheses.
// time complexity: O(2^n)
// space complexity: O(2^n) and using O(n) to store the sequence.