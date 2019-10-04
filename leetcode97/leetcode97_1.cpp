class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> memo(n1, vector(n2, -1));
        
        return dfs(s1, 0, s2, 0, s3, 0, memo);
    }
    
    bool dfs(string& s1, int i, string& s2, int j, string& s3, int k, vector<vector<int>>& memo) {
        if (i == s1.length())
            return s2.substr(j) == s3.substr(k);
        if (j == s2.length())
            return s1.substr(i) == s3.substr(k);
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        
        bool ans = false;
        if ((s3[k] == s1[i] && dfs(s1, i + 1, s2, j, s3, k + 1, memo))
           || s3[k] == s2[j] && dfs(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }
        
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
};

// Runtime: 4 ms, faster than 79.09% of C++ online submissions for Interleaving String.
// Memory Usage: 9.2 MB, less than 7.14% of C++ online submissions for Interleaving String.
// time complexity: O(2^(m + n))
// space complexity: O(mn)