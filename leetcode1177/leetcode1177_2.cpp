class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bitset<26>> prefix_sum(1, bitset<26>("0000000000000000000000000"));
        bitset<26> mask("0000000000000000000000000");
        
        for (auto& c: s) {
            mask ^= 1 << (c - 'a');
            prefix_sum.push_back(mask);
        }
        
        vector<bool> output;
        for (auto& q: queries) {
            int left = q[0], right = q[1], arrange = q[2];
            int odds_count = ((prefix_sum[right + 1] ^ prefix_sum[left])).count();
            output.push_back(arrange >= odds_count / 2);
        }
        
        return output;
    }
};
// Runtime: 248 ms, faster than 79.67% of C++ online submissions for Can Make Palindrome from Substring.
// Memory Usage: 66.4 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.
// time complexity: O(s + n)
// space complexity: O(1)