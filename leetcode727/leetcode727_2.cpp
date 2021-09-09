class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size();
        int next[m+1][26];
        s1 = "#" + s1;
        
        for (int ch = 0; ch < 26; ch++)
            next[m][ch] = -1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int ch = 0; ch < 26; ch++)
                next[i][ch] = next[i + 1][ch];
            next[i][s1[i + 1] - 'a'] = i + 1;
        }
        
        vector<int> start;
        for (int i = 1; i <= m; i++)
        {
            if (s1[i] == s2[0])
                start.push_back(i);
        }
        
        string ret = "";
        for (int i: start)
        {
            int j = i - 1;
            int flag = 1;
            for (auto ch: s2)
            {
                j = next[j][ch - 'a'];
                if (j == -1)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                int len = j - i + 1;
                if (ret == "" || len < ret.size())
                {
                    ret = s1.substr(i, len);
                }
            }        
        }
        
        return ret;
    }
};

// Runtime: 229 ms, faster than 35.97% of C++ online submissions for Minimum Window Subsequence.
// Memory Usage: 393.4 MB, less than 5.14% of C++ online submissions for Minimum Window Subsequence.
// time complexity: O((M+N)*K) m is len of S, n is len of T and k is how many time T[0] shows in S
// space complexity: O(M)
// https://github.com/wisdompeak/LeetCode/tree/master/Greedy/727.Minimum-Window-Subsequence
// https://www.youtube.com/watch?v=c8AgVpUtkwE&ab_channel=HuifengGuan