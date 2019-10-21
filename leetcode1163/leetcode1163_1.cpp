class Solution {
public:
    string lastSubstring(string s) {
        int start = 0, current = 1, len = 0;
        int n = s.length();
        
        while (current + len < n) {
            // compare two substring from start and current
            if (s[start + len] == s[current + len]) {
                ++len;
                continue;
            }
            // current is smaller
            else if (s[start + len] > s[current + len]) {
                current = current + len + 1;
            }
            // current is bigger
            else {
                // nnnnnnnnz pick start + len + 1 which will be z
                // abcdabch pick start to current, which will be abch
                start = max(start + len + 1, current);
                current = start + 1;
            }
            len = 0;
        }
        
        return s.substr(start);
    }
};

// Runtime: 52 ms, faster than 47.80% of C++ online submissions for Last Substring in Lexicographical Order.
// Memory Usage: 16.5 MB, less than 100.00% of C++ online submissions for Last Substring in Lexicographical Order.
// time complexity: O(n)
// space complexity: O(1)

// class Solution:
//     def lastSubstring(self, s: str) -> str:
//         i, j, k = 0, 1, 0
//         n = len(s)
//         while j + k < n:
//             if s[i+k] == s[j+k]:
//                 k += 1
//                 continue
//             elif s[i+k] > s[j+k]:
//                 j = j + k + 1
//             else:
//                 i = max(i + k + 1, j)
//                 j = i + 1
//             k = 0
//         return s[i:]
