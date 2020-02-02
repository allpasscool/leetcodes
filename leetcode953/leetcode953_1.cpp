class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int char_to_num[26];
        
        for (int i = 0; i < order.length(); ++i) {
            char_to_num[order[i] - 'a'] = i;
        }
        
        for (int i = 1; i < words.size(); ++i) {
            bool same = true;
            
            for (int j = 0; j < min(words[i - 1].length(), words[i].length()); ++j) {
                if (words[i - 1][j] != words[i][j]) {
                    if (char_to_num[words[i - 1][j] - 'a'] > char_to_num[words[i][j] - 'a']) {
                        return false;
                    }
                    
                    same = false;
                    break;
                }
            }
            
            if (same && words[i - 1].length() > words[i].length()) {
                return false;
            }
        }
        
        return true;
    }
};


// Runtime: 4 ms, faster than 96.65% of C++ online submissions for Verifying an Alien Dictionary.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Verifying an Alien Dictionary.
// time complexity: O(c)
// space complexity: O(1)