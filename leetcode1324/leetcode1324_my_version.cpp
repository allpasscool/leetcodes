class Solution {
public:
    vector<string> printVertically(string s) {
        
        vector<string> str;
        int start = 0;
        int max_l = 0;
        
        for (int i = 0; i < s.length();) {
            while (i < s.length() && s[i] != ' ') {
                ++i;
            }
            
            str.push_back(s.substr(start, i - start));
            max_l = max(max_l, i - start);
            start = i + 1;
            ++i;
        }
        
        vector<string> output(max_l);
        
        for (int i = 0; i < str.size(); ++i) {
            for (int j = 0; j < max_l; ++j) {
                if (j >= str[i].length()) {
                    output[j] += ' ';
                }
                else {
                    output[j] += str[i][j];
                }
            }
        }
        
        for (int i = 0; i < output.size(); ++i) {
            for (int j = output[i].length() - 1; j >= 0; j--) {
                if (j == output[i].length() - 1 && output[i][j] != ' ') {
                    break;
                }
                else if (j == 0 && output[i][j] == ' ') {
                    output[i] = "";
                    break;
                }
                else if (output[i][j] != ' ') {
                    output[i] = output[i].substr(0, j + 1);
                    break;
                }
            }
        }
        
        return output;
    }
};


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Print Words Vertically.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Print Words Vertically.
// time complexity: O(n)
// space complexity: O(n)