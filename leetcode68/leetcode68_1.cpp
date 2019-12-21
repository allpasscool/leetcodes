class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        
        for (int i = 0, j, len; i < words.size(); i += j) {
            for (j = len = 0; i + j < words.size() && len + words[i + j].size() <= maxWidth - j; ++j) {
                len += words[i + j].size();
            }
            
            string tmp = words[i];
            
            for (int k = 0; k < j - 1; ++k) {
                if (i + j >= words.size()) {
                    tmp += " ";
                }
                else {
                    tmp += string((maxWidth - len) / (j - 1) + (k < (maxWidth - len) % (j - 1)), ' ');
                }
                tmp += words[i + k + 1];
            }
            
            tmp += string(maxWidth - tmp.size(), ' ');
            ans.push_back(tmp);
        }
        
        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Text Justification.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Text Justification.
// time complexity: O(n)
// space complexity: O(1)

// https://leetcode.com/problems/text-justification/discuss/24873/Share-my-concise-c%2B%2B-solution-less-than-20-lines

// vector<string> fullJustify(vector<string> &words, int L) {
//     vector<string> res;
//     for(int i = 0, k, l; i < words.size(); i += k) {
//         for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
//             l += words[i+k].size();
//         }
//         string tmp = words[i];
//         for(int j = 0; j < k - 1; j++) {
//             if(i + k >= words.size()) tmp += " ";
//             else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
//             tmp += words[i+j+1];
//         }
//         tmp += string(L - tmp.size(), ' ');
//         res.push_back(tmp);
//     }
//     return res;
// }