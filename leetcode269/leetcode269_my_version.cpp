class Solution {
public:
    string alienOrder(vector<string>& words) {
        // topological sort
        unordered_map<char, int> ranks;
        unordered_map<char, unordered_set<char>> graphs; // graphs[i] = {j, k} means node i points to node j and node k
        unordered_set<char> chars;
        
        string pre = "";
        for (auto word : words) {
            chars.insert(word.begin(), word.end());
            // cols
            for (int i = 0; i < min(pre.length(), word.length()); ++i) {
                if (pre[i] != word[i]) {
                    if (graphs[pre[i]].find(word[i]) == graphs[pre[i]].end()) {
                        ++ranks[word[i]];
                        graphs[pre[i]].insert(word[i]); 
                    }
                    break;
                }
            }
            
            pre = word;
        }
        
        queue<char> q;
        for (auto c : chars) {
            if (ranks[c] == 0) {
                q.push(c);
            }
        }
        
        string ans = "";
        while (!q.empty()) {
            char front = q.front();
            q.pop();
            ans += front;
            
            for (auto c : graphs[front]) {
                ranks[c]--;
                if (ranks[c] == 0) {
                    q.push(c);
                }
            }
        }
        
        return (ans.length() == chars.size()) ? ans : "";
    }
};


// Runtime: 4 ms, faster than 85.96% of C++ online submissions for Alien Dictionary.
// Memory Usage: 9.4 MB, less than 92.86% of C++ online submissions for Alien Dictionary.
// time complexity: O(n)
// space complexity: O(n^2)