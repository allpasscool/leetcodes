class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> char_to_num;
        
        for (int i = 0; i < order.length(); ++i) {
            char_to_num[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); ++i) {
            bool same = true;
            
            for (int j = 0; j < min(words[i - 1].length(), words[i].length()); ++j) {
                if (words[i - 1][j] != words[i][j]) {
                    if (char_to_num[words[i - 1][j]] > char_to_num[words[i][j]]) {
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
// Memory Usage: 9.3 MB, less than 53.85% of C++ online submissions for Verifying an Alien Dictionary.
// time complexity: O(n)
// space complexity: O(n)