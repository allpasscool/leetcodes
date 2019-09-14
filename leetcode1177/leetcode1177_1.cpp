class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> output;
        vector<vector<int>> alpha_count(s.size(), vector<int> (26, 0));
        vector<int> tmp(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            tmp[c]++;
            alpha_count[i] = tmp;
        }
        
        for (int i = 0; i < n; i++) {
            int left = queries[i][0], right = queries[i][1], replace = queries[i][2];
            
            int count = 0;
            for (int j = 0; j < 26; j++) {
                count += left == 0 ? alpha_count[right][j] % 2: (alpha_count[right][j] - alpha_count[left - 1][j]) % 2;
            }
            
            if (count / 2 > replace) {
                output.push_back(false);
            }
            else {
                output.push_back(true);
            }
        }
        
        
        return output;
    }
};
// Runtime: 388 ms, faster than 29.93% of C++ online submissions for Can Make Palindrome from Substring.
// Memory Usage: 111.9 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
// time complexity: O(s.size() + queries.size())
// space complexity: O(26^n)