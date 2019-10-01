class Solution {
public:
    string removeDuplicates(string s, int k) {
        int pos = 0, n = s.length();
        vector<int> count(n, 0);
        
        for (int i = 0; i < n; ++i, ++pos) {
            s[pos] = s[i];
            
            if (pos > 0 && s[pos - 1] == s[i]) {
                count[pos] = count[pos - 1] + 1;
            }
            else {
                count[pos] = 1;
            }
            
            if (count[pos] == k)
                pos -= k;
        }
        
        return s.substr(0, pos);
    }
};

// Runtime: 12 ms, faster than 89.10% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// Memory Usage: 11 MB, less than 100.00% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// time complexity: O(n)
// space complexity: O(n)