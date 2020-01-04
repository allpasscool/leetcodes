class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        max_len = 0;
        
        for (auto s : wordDict) {
            hashset.insert(s);
            max_len = max(max_len, (int)s.length());
        }
        
        for (int i = 1; i <= max_len; ++i) {
            string tmp = s.substr(0, i);
            if (hashset.find(tmp) != hashset.end()) {
                wordBreakSub(s, i);
                
                for (auto right : mem[i]) {
                    output.push_back(tmp + " " + right);
                }
                
                if (i == s.length()) {
                    output.push_back(tmp);
                }
            }
        }
        
        return output;
    }
    
private:
    void wordBreakSub(string& s, int start) {
        
        if (start == s.length()) {
            return;
        }
        
        vector<string> ans;
        
        for (int i = 1; start + i <= s.length() && i <= max_len; ++i) {
            string tmp = s.substr(start, i);
            if (hashset.find(tmp) != hashset.end()) {
                if (start + i == s.length()) {
                    ans.push_back(tmp);
                    break;
                }
                
                
                if (mem.find(start + i) == mem.end()) {
                    wordBreakSub(s, start + i);
                }
                
                if (mem[start + i].size() > 0) {
                    for (auto right : mem[start + i]) {
                        ans.push_back(tmp + " " + right);
                    }
                }
            }
        }
        
        mem[start].swap(ans);
        return;
    }
                    
    unordered_map<int, vector<string>> mem;
    vector<string> output;
    unordered_set<string> hashset;
    int max_len;
};

// Runtime: 8 ms, faster than 95.59% of C++ online submissions for Word Break II.
// Memory Usage: 10.7 MB, less than 93.94% of C++ online submissions for Word Break II.
// time complexity: O(2^n)
// space complexity: O(2^n)
// http://zxi.mytechroad.com/blog/leetcode/leetcode-140-word-break-ii/

// // Author: Huahua
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
//         return wordBreak(s, dict);
//     }
// private:
//     // >> append({"cats and", "cat sand"}, "dog");
//     // {"cats and dog", "cat sand dog"}
//     vector<string> append(const vector<string>& prefixes, const string& word) {
//         vector<string> results;
//         for(const auto& prefix : prefixes)
//             results.push_back(prefix + " " + word);
//         return results;
//     }
    
//     const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
//         // Already in memory, return directly
//         if(mem_.count(s)) return mem_[s];
        
//         // Answer for s
//         vector<string> ans;
        
//         // s in dict, add it to the answer array
//         if(dict.count(s)) 
//             ans.push_back(s);
        
//         for(int j=1;j<s.length();++j) {
//             // Check whether right part is a word
//             const string& right = s.substr(j);
//             if (!dict.count(right)) continue;
            
//             // Get the ans for left part
//             const string& left = s.substr(0, j);
//             const vector<string> left_ans = 
//                 append(wordBreak(left, dict), right);
            
//             // Notice, can not use mem_ here,
//             // since we haven't got the ans for s yet.
//             ans.insert(ans.end(), left_ans.begin(), left_ans.end());
//         }
        
//         // memorize and return
//         mem_[s].swap(ans);
//         return mem_[s];
//     }
// private:
//     unordered_map<string, vector<string>> mem_;
// };