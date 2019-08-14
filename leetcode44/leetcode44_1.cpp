class Solution {
public:
    std::map<pair<string, string>, bool> dp_map;
        
    string removeDulpicateStars(string p) {
        if (p == "") {
            return p;
        }
        
        string p1 = "" + p[0];
        
        for (int i = 1; i < p.length(); i++) {
            if (p1[i - 1] != '*' || (p1[i - 1] == '*' && p[i] != '*')) {
                p1 += p[i];
            }
        }
        
        return p1;
    }
    
    bool helper(string s, string p) {
        if (dp_map.find(pair<string, string> (s, p)) != dp_map.end()) {
            return dp_map[pair<string, string> (s, p)];
        }
        
        pair<string, string> current(s, p);
        
        if (p == s || p == "*") {
            dp_map[current] = true;
        } else if (p == "" || s == "") {
            dp_map[current] = false;
        } else if (p[0] == s[0] || p[0] == '?') {
            dp_map[current] = helper(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
        } else if (p[0] == '*') {
            dp_map[current] = helper(s, p.substr(1, p.length() - 1))
                || helper(s.substr(1, s.length() - 1), p);
        } else {
            dp_map[current] = false;
        }
        
        return dp_map[current];
    }
    
    bool isMatch(string s, string p) {
        p = removeDulpicateStars(p);
        // memorization hashmap to be used during the recursion
        return helper(s, p);
    }
};
//global buffer overflow
// Time complexity: O(min(S,P)) for the best case, and O(2 ^ min(S,P/2)) for the worst case, where S and P are lengths of the input string and the pattern correspondingly. 
// The best case is quite obvious, let's estimate the worst case. The most time consuming is the situation where recursion forms the tree on the star character in the pattern.
// In this situation 2 branches are executed : helper(s, p[1:]) and helper(s[1:], p). The maximum number of stars in the pattern after data cleanup is P/2 and hence the time complexity is O(2 ^ min(S,P/2)).
// Space complexity: O(2 ^ min(S,P/2)) to keep the memorisation hashmap and the recursion stack. 
