class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        vector<pair<string, string>> first_and_last(phrases.size()); // this index's first word and last word
        unordered_map<string, vector<int>> first_word, last_word;
        
        // get all first word and last word
        for (int i = 0; i < phrases.size(); ++i) {
            
            // first word
            int start = 0;
            while (start < phrases[i].length()) {
                if (!isalpha(phrases[i][start])) {
                    break;
                }
                ++start;
            }
            first_word[phrases[i].substr(0, start)].push_back(i);
            first_and_last[i].first = phrases[i].substr(0, start);
            
            // last word
            start = phrases[i].length() - 1;
            while (start > 0) {
                if (!isalpha(phrases[i][start])) {
                    ++start;
                    break;
                }
                start--;
            }
            last_word[phrases[i].substr(start)].push_back(i);
            first_and_last[i].second = phrases[i].substr(start);
        }
        
        set<string> ans;
        
        for (int i = 0; i < first_and_last.size(); ++i) {
            string& last_w = first_and_last[i].second;
            
            if (first_word.find(last_w) != first_word.end()) {
                for (auto index : first_word[last_w]) {
                    if (i != index) {
                        ans.insert(phrases[i] + phrases[index].substr(last_w.length()));
                    }
                }
            }
        }
        
        vector<string> output(ans.size());
        
        int counter = 0;
        for (auto s : ans) {
            output[counter] = s;
            ++counter;
        }
        
        return output;
    }
};


// Runtime: 12 ms, faster than 81.39% of C++ online submissions for Before and After Puzzle.
// Memory Usage: 13.1 MB, less than 100.00% of C++ online submissions for Before and After Puzzle.
// time complexity: O(n^2)
// space complexity: O(n)