class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        
        if(n == 0){
            output.push_back("");
        }
        else{
            for(int i = 0; i < n; i++){
                for(string left: generateParenthesis(i)){
                    for(string right: generateParenthesis(n-1-i)){
                        output.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        
        return output;
    }
};
// Runtime: 8 ms, faster than 62.75% of C++ online submissions for Generate Parentheses.
// Memory Usage: 15.3 MB, less than 74.45% of C++ online submissions for Generate Parentheses.
// time complexity: O(2^n)
// space complexity: O(2^n)