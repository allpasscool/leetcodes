class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_count;
        
        for (int i = 0; i < chars.length(); i++) {
            if (chars_count.find(chars[i]) == chars_count.end()) {
                chars_count[chars[i]] = 1;
            } 
            else {
                chars_count[chars[i]]++;
            }
        }
        
        int output = 0;
        
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> word_map;
            bool count_true = true;
            
            for (int j = 0; j < words[i].length(); j++) {
                if (chars_count.find(words[i][j]) == chars_count.end()) {
                    count_true = false;
                    break;
                }
                else{ 
                    if (word_map.find(words[i][j]) == word_map.end()) {
                        word_map[words[i][j]] = 1;
                    }
                    else {
                        word_map[words[i][j]]++;
                    }
                    
                    if (word_map[words[i][j]] > chars_count[words[i][j]]) {
                        count_true = false;
                        break;
                    }
                
                }
            }
            
            if (count_true) {
                output += words[i].length();
            }
        }
        
        return output;
    }
};
// Runtime: 116 ms, faster than 34.28% of C++ online submissions for Find Words That Can Be Formed by Characters.
// Memory Usage: 25 MB, less than 100.00% of C++ online submissions for Find Words That Can Be Formed by Characters.
// time complexity: O(n + m), n i #of characters in words , and m is # of chars
// space complexity: O(m)