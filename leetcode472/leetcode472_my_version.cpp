class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // wordset.insert(words.begin(), words.end());
        for (auto word : words) {
            if (word.length() > 0) {
                wordset.insert(word);
            }
        }
        
        vector<string> output;
        
        for (auto word : words) {
            // concated words at least len >= 2
            if (word.length() > 1 && isConcatenate(word, 0)) {
                output.push_back(word);
            }
        }
        
        return output;
    }
    
private:
    unordered_set<string> wordset;
    unordered_map<string, bool> isConcate;
    
    // special case 
    // input [""]
    // output []
    bool isConcatenate(string& word, int start) {
        if (start == word.length()) {
            return true;
        }
        // dp, memory
        string first_word = word.substr(start);
        if (isConcate.find(first_word) != isConcate.end()) {
            return isConcate[first_word];
        }
        
        // first word len
        for (int len = 1; start + len <= word.length(); ++len) {
            // first word
            string tmp = word.substr(start, len);
            if (wordset.find(tmp) != wordset.end()) {
                // word = tmp + sub_str
                string sub_str = word.substr(start + len);
                
                // last one word?
                if (wordset.find(sub_str) != wordset.end()) {
                    return isConcate[word] = true;
                }
                // last multilple words?
                else {
                    isConcate[sub_str] = isConcatenate(word, start + len);
                }
                
                // special case only one word
                if (isConcate[sub_str] && !(start == 0 && len == word.length())) {
                    return true;
                }
            }
        }
        
        // isConcate[first_word] = false;
        return false;
    }
};


// Runtime: 248 ms, faster than 80.36% of C++ online submissions for Concatenated Words.
// Memory Usage: 47.3 MB, less than 83.33% of C++ online submissions for Concatenated Words.
// time complexity: O(n * m)
// space complexity: O(n * m), m is maxlen(word)