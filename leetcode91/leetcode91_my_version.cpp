class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> ways(n, 0);
        // invalid
        if (n == 0 || s[0] == '0')
            return 0;
        
        
        if (n >= 1 && s[0] != '0') {
            ways[0] = 1;
        }
        if (n >= 2) {
            if (s[0] < '2' && s[1] != '0')
                ways[1] = 2;
            else if (s[0] <= '2' && s[1] == '0')
                ways[1] = 1;
            else if (s[0] == '2' && s[1] <= '6')
                ways[1] = 2;
            else if (s[0] == '2' && s[1] >= '7')
                ways[1] = 1;
            else if (s[0] >= '3' && s[1] != '0')
                ways[1] = 1;
            // invalid
            else if (s[0] >= '3' && s[1] == '0')
                return 0;
        }
        
        for (int i = 2; i < n; ++i) {
            if (s[i] != '0')
                ways[i] += ways[i - 1];
            
            if (s[i - 1] > '0' 
                && (s[i - 1] < '2' || (s[i - 1] == '2' && s[i] <= '6')))
                ways[i] += ways[i - 2];
            
            // can't decode
            if (ways[i] == 0)
                return 0;
        }
        
        return ways[n - 1];
    }
};

// Runtime: 4 ms, faster than 65.13% of C++ online submissions for Decode Ways.
// Memory Usage: 8.6 MB, less than 47.06% of C++ online submissions for Decode Ways.
// time complexity: O(n)
// space complexity: O(n)