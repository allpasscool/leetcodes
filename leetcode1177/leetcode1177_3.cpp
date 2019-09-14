class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> prefix_sum(1, 0);
        int mask = 0;
        
        for (auto& c: s) {
            mask ^= 1 << c - 'a';
            prefix_sum.push_back(mask);
        }
        
        vector<bool> output;
        for (auto& q: queries) {
            int left = q[0], right = q[1], arrange = q[2];
            int odds_count = __builtin_popcount(prefix_sum[right + 1] ^ prefix_sum[left]);
            output.push_back(arrange >= odds_count / 2);
        }
        
        return output;
    }
// };
// Runtime: 268 ms, faster than 64.76% of C++ online submissions for Can Make Palindrome from Substring.
// Memory Usage: 64 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
// time complexity: O(s + n)
// space complexity: O(1)