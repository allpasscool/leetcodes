class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> char_to_row;
        
        char_to_row['Q'] = 0;
        char_to_row['q'] = 0;
        char_to_row['W'] = 0;
        char_to_row['w'] = 0;
        char_to_row['E'] = 0;
        char_to_row['e'] = 0;
        char_to_row['R'] = 0;
        char_to_row['r'] = 0;
        char_to_row['T'] = 0;
        char_to_row['t'] = 0;
        char_to_row['Y'] = 0;
        char_to_row['y'] = 0;
        char_to_row['U'] = 0;
        char_to_row['u'] = 0;
        char_to_row['I'] = 0;
        char_to_row['i'] = 0;
        char_to_row['O'] = 0;
        char_to_row['o'] = 0;
        char_to_row['P'] = 0;
        char_to_row['p'] = 0;
        
        char_to_row['A'] = 1;
        char_to_row['a'] = 1;
        char_to_row['S'] = 1;
        char_to_row['s'] = 1;
        char_to_row['D'] = 1;
        char_to_row['d'] = 1;
        char_to_row['F'] = 1;
        char_to_row['f'] = 1;
        char_to_row['G'] = 1;
        char_to_row['g'] = 1;
        char_to_row['H'] = 1;
        char_to_row['h'] = 1;
        char_to_row['J'] = 1;
        char_to_row['j'] = 1;
        char_to_row['K'] = 1;
        char_to_row['k'] = 1;
        char_to_row['L'] = 1;
        char_to_row['l'] = 1;
        
        char_to_row['Z'] = 2;
        char_to_row['z'] = 2;
        char_to_row['X'] = 2;
        char_to_row['x'] = 2;
        char_to_row['C'] = 2;
        char_to_row['c'] = 2;
        char_to_row['V'] = 2;
        char_to_row['v'] = 2;
        char_to_row['B'] = 2;
        char_to_row['b'] = 2;
        char_to_row['N'] = 2;
        char_to_row['n'] = 2;
        char_to_row['M'] = 2;
        char_to_row['m'] = 2;
        
        vector<string> output;
        
        for (auto& s: words) {
            bool same_row = true;
            
            for (int i = 0; i < s.length() - 1; i++) {
                if (char_to_row[s[i]] != char_to_row[s[i + 1]]) {
                    same_row = false;
                    break;
                }
            }
            
            if (same_row)
                output.push_back(s);
        }
        
        
        return output;
    }
};

// Runtime: 4 ms, faster than 52.86% of C++ online submissions for Keyboard Row.
// Memory Usage: 8.7 MB, less than 14.29% of C++ online sub
// time complexity: O(n)
// space complexity: O(1)