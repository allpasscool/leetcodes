class Solution {
public:
    string reorganizeString(string S) {
        vector<int> chars(26);
        int n = S.length();
        
        for (auto c : S) {
            ++chars[c - 'a'];
        }
        
        vector<pair<int, char>> char_counts;
        for (int i = 0; i < 26; ++i) {
            if (chars[i] > (n + 1) / 2)
                return "";
            else if (chars[i]) {
                char_counts.push_back({chars[i], i + 'a'});
            }
        }
        
        sort(rbegin(char_counts), rend(char_counts));
        
        string sorted_S;
        for (auto& p : char_counts) {
            sorted_S += string(p.first, p.second);
        }
        
        string ans;
        for (int i = 0, j = (n - 1) / 2 + 1; i <= (n - 1) / 2; ++i, ++j) {
            ans += sorted_S[i];
            if (j < n) {
                ans +=sorted_S[j];
            }
        }
        
        return ans;
    }
};


// Runtime: 4 ms, faster than 73.20% of C++ online submissions for Reorganize String.
// Memory Usage: 8.7 MB, less than 70.59% of C++ online submissions for Reorganize String.
// time complexity: O(n log n)
// space complexity: O(n)

// https://leetcode.com/problems/reorganize-string/discuss/113427/C%2B%2B-Greedy-sort-O(N)
// class Solution {
// public:
//     string reorganizeString(string S) {
//         vector<int> mp(26);
//         int n = S.size();
//         for (char c: S) ++mp[c-'a'];
//         vector<pair<int, char>> charCounts;
//         for (int i = 0; i < 26; ++i) {
//             if (mp[i] > (n+1)/2) return "";
//             if (mp[i]) charCounts.push_back({mp[i], i+'a'});
//         }
//         sort(charCounts.rbegin(), charCounts.rend());
//         string strSorted;
//         for (auto& p: charCounts)
//             strSorted += string(p.first, p.second);
//         string ans;
//         for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
//             ans += strSorted[i];
//             if (j < n) ans += strSorted[j];
//         }
//         return ans;
//     }
// };