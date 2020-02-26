class Solution {
public:
    string reorganizeString(string S) {
        int n = S.length();
        
        vector<int> chars(26);
        
        int max_char = 0;
        for (auto c : S) {
            ++chars[c - 'a'];
            max_char = max(max_char, chars[c - 'a']);
        }
        
        // one chars has more than (n + 1) / 2
        if (max_char > (n + 1) / 2) {
            return "";
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (chars[i] > 0) {
                pq.push({chars[i], 'a' + i});
            }
        }
        
        // find output
        string output;
        
        while (!pq.empty()) {
            pair<int, char> cur = pq.top();
            pq.pop();
            if (cur.first == 0)
                continue;
            
            // last char is the same as top in pq
            if (output.length() > 0 && output.back() == cur.second) {
                pair<int, char> tmp = pq.top();
                pq.pop();
                output += tmp.second;
                tmp.first--;
                pq.push(tmp);
            }
            else {
                output += cur.second;
                cur.first--;
            }
            
            pq.push(cur);
        }
        
        return output;
    }
};


// Runtime: 4 ms, faster than 73.20% of C++ online submissions for Reorganize String.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Reorganize String.
// time complexity: O(n log n)
// space complexity: O(n)