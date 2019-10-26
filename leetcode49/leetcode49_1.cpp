class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        
        for (auto s: strs) {
            int count[26] = {0};
            
            for (auto c: s) {
                ++count[c - 'a'];
            }
            
            string key = "";
            for (int i = 0; i < 26; ++i) {
                if (count[i] != 0) {
                    key += to_string(count[i]) + string(1, 'a' + i);
                }
            }
            
            hashmap[key].push_back(s);
        }
        
        vector<vector<string>> output;
        
        for (auto p: hashmap) {
            output.push_back(p.second);
        }
        
        return output;
    }
};

// Runtime: 60 ms, faster than 21.79% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.9 MB, less than 58.21% of C++ online submissions for Group Anagrams.
// time complexity: O(nk)
// space complexity: O(nk)