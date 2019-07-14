class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp_table[s.size() + 1][p.size() + 1];
        
        dp_table[s.size()][p.size()] = true;
        
        for(int i = 0; i < s.size(); i++){
            dp_table[i][p.size()] = false;
        }
        
        for(int i = 0; i < p.size(); i++){
            bool ans = true;
            
            if((p.size() - i) % 2 == 0){
                for(int j = i; j < p.size(); j += 2){
                    if(p[j+1] != '*'){
                        ans = false;
                        break;
                    }
                }
            }else{
                ans = false;
            }
            
            dp_table[s.size()][i] = ans;
        }
        
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = p.size() - 1; j >= 0; j--){
                
                bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
                
                if(j + 1 < p.size() && p[j+1] == '*'){
                    dp_table[i][j] = dp_table[i][j+2] || first_match && dp_table[i+1][j];
                }
                else{
                    dp_table[i][j] = first_match && dp_table[i+1][j+1];
                }
            }
        }
        
        // for(int i = s.size(); i >= 0; i--){
        //     for(int j = 0; j <= p.size(); j++){
        //         std::cout << dp_table[i][j] << " ";
        //     }
        //     std::cout << endl;
        // }
        
        return dp_table[0][0];
    }
};
// Runtime: 4 ms, faster than 95.49% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 8.2 MB, less than 93.37% of C++ online submissions for Regular Expression Matching.
//time complexity: O(TP)
//space complexity: O(TP)