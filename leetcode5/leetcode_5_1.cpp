class Solution {
public:
    string longestPalindrome(string s) {
        std::vector<std::vector<bool>> dp_table;
        
        //tmp row
        std::vector<bool> tmp_row(s.size());
        
        //ceate dp table with all false
        for(int i = 0; i < s.size(); i++){
            dp_table.push_back(tmp_row);
        }
        
        //p(i,i) = true, p(i, i+1) = (Si == Si+1)
        for(int i = 0; i < s.size(); i++){
            dp_table[i][i] = true;
            
            if(i < s.size() - 1){
                dp_table[i][i+1] = (s[i] == s[i+1]);
            }
        }
        
        int max_len = 1;
        int start = 0, end = 0;
        
        //fill dp table
        for(int i = s.size()-2; i >= 0; i--){
            for(int j = s.size()-1; j > i; j--){
                dp_table[i][j] = (dp_table[i+1][j-1] && (s[i] == s[j]));
                if(i+1 > j-1){
                    dp_table[i][j] = (s[i] == s[j]);
                }
                
                if(dp_table[i][j] == true && (j-i+1 >= max_len)){
                    start = i;
                    end = j;
                    max_len = j-i+1;
                }
            }
        }
        
        return s.substr(start, (end-start+1));
    }
};

// Runtime: 412 ms, faster than 7.27% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 21.4 MB, less than 28.86% of C++ online submissions for Longest Palindromic Substring.
//time complexity: O(n^2)
//space complexity: O(n^2)