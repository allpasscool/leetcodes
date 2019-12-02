class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hashmap;
        
        for (auto s : paths) {
            int i = 0;
            
            // find (content)
            while (s[i] != ' ') {
                ++i;
            }
            
            string location = s.substr(0, i);
            
            ++i;
            int start = i;
            while (i < s.length()) {
                int content_left, content_right;
                // get file name and content
                while (s[i] != ' ' && i < s.length()) {
                    if (s[i] == '(') {
                        content_left = i;
                    }
                    else if (s[i] == ')') {
                        content_right = i;
                    }
                    ++i;
                }
                
                string content = s.substr(content_left, content_right - content_left + 1);
                string file = s.substr(start, content_left - start);
                ++i;
                start = i;
                
                hashmap[content].push_back(location + '/' + file);
            }
        }
        
        vector<vector<string>> ans;
        
        for (auto p : hashmap) {
            string content = p.first;
            if (p.second.size() <= 1) 
                continue;
            
            ans.push_back(p.second);
        }
        
        return ans;
    }
};


// Runtime: 116 ms, faster than 69.88% of C++ online submissions for Find Duplicate File in System.
// Memory Usage: 43.5 MB, less than 66.67% of C++ online submissions for Find Duplicate File in System.
// time complexity: O(n)
// space complexity: O(n)