class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() >= 4 && p[0] == p[2] && p[1] == p[3]){
            return isMatch(s, p.substr(2, p.size()-2));
        }
        
        
        std::vector<std::vector<bool>> dp_table;
        
        std::vector<bool> tmp(p.size() + 1, NULL);
        for(int i = 0; i <= s.size(); i++){
            dp_table.push_back(tmp);
        }
        
        return dp(0, 0, s, p, dp_table);
    }
    
    bool dp(int i, int j, string s, string p, std::vector<std::vector<bool>> &dp_table){
        if(dp_table[i][j] != NULL){
            return dp_table[i][j];
        }
        
        bool ans;
        if(j == p.size()){
            ans = i == s.size();
        }
        else{
            bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
            
            if(j + 1 < p.size() && p[j+1] == '*'){
                ans = (dp(i, j+2, s, p, dp_table) || first_match && dp(i+1, j, s, p, dp_table));
            }
            else{
                ans = first_match && dp(i+1, j+1, s, p, dp_table);
            }
        }
        
        dp_table[i][j] = ans;
        return ans;
    }
};
// Runtime: 520 ms, faster than 5.02% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 305 MB, less than 5.04% of C++ online submissions for Regular Expression Matching.
//Time complexity: O(TP), T and P  be the lengths of the text and the pattern respectively. 
//space complexity: O(TP)