class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letter_logs;
        vector<int> digit_logs;
        
        for (int i = 0; i < logs.size(); ++i) {
            int pos = 0;
            while (logs[i][pos] != ' ')
                ++pos;
            
            if (logs[i][pos + 1] >= 'a' && logs[i][pos + 1] <= 'z')
                letter_logs.emplace_back(logs[i].substr(0, pos), logs[i].substr(pos + 1));
            else if (logs[i][pos + 1] >= '0' && logs[i][pos + 1] <= '9')
                digit_logs.push_back(i);
        }
        
        sort(letter_logs.begin(), letter_logs.end(), compLetters);
        
        vector<string> output;
        
        for(auto s : letter_logs) {
            output.emplace_back(s.first + ' ' +s.second);
        }
        for (auto pos : digit_logs) {
            output.push_back(logs[pos]);
        }
        
        return output;
    }
private:
    static bool compLetters(pair<string, string> s1, pair<string, string> s2) {
        return s1.second == s2.second ? s1.first < s2.first : s1.second < s2.second;
    }
};

// Runtime: 8 ms, faster than 98.62% of C++ online submissions for Reorder Data in Log Files.
// Memory Usage: 14.6 MB, less than 47.06% of C++ online submissions for Reorder Data in Log Files.
// time complexity: O(n log n)
// space complexity: O(n)
// https://leetcode.com/problems/reorder-data-in-log-files/discuss/192438/C%2B%2B-O(NlogN)-Time-O(N)-Space