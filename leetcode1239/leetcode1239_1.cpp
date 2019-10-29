class Solution {
public:
    int maxLength(vector<string>& arr) {
        // we convert each string into binary,
        // 32 bits > 26 alpha, and we only keep string don't have duplicate alphabet
        vector<int> strs;
        
        // push valid stinrg in arr into strs
        for (const string& x : arr) {
            set<char> s(x.begin(), x.end());
            // this string has dulpicated alphabet
            if (s.size() != x.length())
                continue;
            
            int alpha_count = 0;
            
            for (char c:  x) {
                alpha_count |= 1 << (c - 'a');
            }
            
            strs.push_back(alpha_count);
            
            // cout << x << endl;
            // cout << alpha_count << endl;
        }
        
        int ans = 0;
        
        // defind dfs function
        function<void(int, int)> dfs = [&](int index, int cur) {
            // __builtin_popcount reutrn num of 1s in cur
            ans = max(ans, __builtin_popcount(cur));
            
            for (int i = index; i < strs.size(); ++i) {
                // cur & strs[i] == 0 means no same bits are 1
                if ((cur & strs[i]) == 0) {
                    // cur | strs[i] means count all alpha in both cur and strs[i]
                    dfs(i + 1, cur | strs[i]);
                }
            }
        };
        
        
        dfs(0, 0);
        return ans;
    }
};


// Runtime: 4 ms, faster than 97.68% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// time complexity: O(2^n)
// space complexity: O(n), deep of dfs

// Author: Huahua
// class Solution {
// public:
//   int maxLength(vector<string>& arr) {
//     vector<int> a;
    
//     for (const string& x : arr) {
//       set<char> s(begin(x), end(x));
//       if (s.size() != x.length()) continue;
//       a.push_back(0);      
//       for (char c : x) a.back() |= 1 << (c - 'a');      
//     }
    
//     int ans = 0;
    
//     function<void(int, int)> dfs = [&](int s, int cur) {
//       ans = max(ans, __builtin_popcount(cur));
//       for (int i = s; i < a.size(); ++i)
//         if ((cur & a[i]) == 0)
//           dfs(i + 1, cur | a[i]);      
//     };
    
//     dfs(0, 0);
//     return ans;
//   }
// };