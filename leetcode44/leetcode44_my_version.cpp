class Solution {
public:
    map<pair<int, int>, bool> dp_map;
    
    bool helper(string& s, string& p, int s_start, int p_start) {
        int n1 = s.length() - s_start, n2 = p.length() - p_start;
        pair<int, int> current_pair = std::make_pair(s_start, p_start);
        
        if (dp_map.find(current_pair) != dp_map.end()) {
            return dp_map[current_pair];
        }
        
        if (n1 == 0 && n2 == 0) {
            dp_map[current_pair] = true;
            return true;
        } else if (n1 == 0) {
            for (int i = 0; i < n2; i++) {
                if(p[i + p_start] != '*') {
                    dp_map[current_pair] = false;
                    return false;
                }
            }
            dp_map[current_pair] = true;
            return true;
        } else if (n2 == 0) {
            dp_map[current_pair] = false;
            return false;
        }
        
        bool is_match = false;

        if (s[s_start] == p[p_start] || p[p_start] == '?') {
            is_match = is_match || helper(s, p, s_start + 1, p_start + 1);
        } else if (p[p_start] == '*') {
            int i = 0;
                
            //eliminate '*'
            for(; i < n2 - 1; i++) {
                if (p[i + p_start + 1] != '*') {
                    break;
                }
            }
            
            is_match = is_match 
                || helper(s, p, s_start, p_start + i + 1)
                || helper(s, p, s_start + 1, p_start + i + 1)
                || helper(s, p, s_start + 1, p_start + i);
        }
        dp_map[current_pair] = is_match;
        return is_match;
    }
    
    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        
        if (n1 == 0 && n2 == 0) {
            return true;
        } else if (n1 == 0) {
            for (int i = 0; i < n2; i++) {
                if(p[i] != '*') {
                    return false;
                }
            }
            
            return true;
        } else if (n2 == 0) {
            return false;
        }
        
        //compare tail
        if ((p[n2 - 1] != '*' && p[n2 - 1] != '?') && p[n2 - 1] != s[n1 - 1]) {
            return false;
        }
        
        bool is_match = false;
        
        if (is_match) {
            return is_match;
        }

        if (s[0] == p[0] || p[0] == '?') {
            // is_match = is_match || isMatch(s.substr(1, n1 - 1), p.substr(1, n2 - 1));
            is_match = is_match || helper(s, p, 1, 1);
        } else if (p[0] == '*') {
            int i = 0;
                
            //eliminate '*'
            for(; i < n2 - 1; i++) {
                if (p[i + 1] != '*') {
                    break;
                }
            }
            
            // is_match = is_match 
            //     || isMatch(s.substr(1, n1 - 1), p.substr(i + 1, n2 - i - 1))
            //     || isMatch(s, p.substr(i + 1, n2 - i - 1))
            //     || isMatch(s.substr(1, n1 - 1), p);
            is_match = is_match 
                || helper(s, p, 1, i + 1)
                || helper(s, p, 0, i + 1)
                || helper(s, p, 1, i);
        }
        
        return is_match;
    }
};
// Runtime: 604 ms, faster than 5.05% of C++ online submissions for Wildcard Matching.
// Memory Usage: 84.3 MB, less than 7.69% of C++ online submissions for Wildcard Matching.
// time complexity: O(s * p)
// space complexity: O(s * p)