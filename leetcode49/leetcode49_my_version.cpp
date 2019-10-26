class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        
        for (auto s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hashmap[tmp].push_back(s);
        }
        
        vector<vector<string>> output;
        
        for (auto p: hashmap) {
            output.push_back(p.second);
        }
        
        return output;
    }
};

// Runtime: 36 ms, faster than 90.61% of C++ online submissions for Group Anagrams.
// Memory Usage: 20 MB, less than 55.22% of C++ online submissions for Group Anagrams.
// time complexity: O(n * k log k) // n is size of strs, k is the len of each string
// space complexity: O(nk)