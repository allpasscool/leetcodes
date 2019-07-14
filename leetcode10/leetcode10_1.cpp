class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0){
            return s.size() == 0;
        }
        
        bool first_match = (!(s.size() == 0) && (s[0] == p[0] || p[0] == '.'));
        
        if(p.size() >= 2 && p[1] == '*'){
            return isMatch(s, p.substr(2, p.size() - 2)) || (first_match && isMatch(s.substr(1, s.size() - 1), p));
        }
        else{
            return first_match && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        }
    }
};
// Runtime: 208 ms, faster than 21.01% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 15.3 MB, less than 19.85% of C++ online submissions for Regular Expression Matching.
//Time Complexity: Let T, P be the lengths of the text and the pattern respectively.  O((T + P) 2^(T + P/2))
//Space Complexity: O((T + P) 2^(T + P/2))