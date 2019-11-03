class Solution {
public:
    string output;
    bool done = false;
    
    string minRemoveToMakeValid(string s) {
        int invalid_close = 0;
        int need_close = 0;
        vector<char> new_s;
        
        for (auto c : s) {
            if (c == '(') {
                new_s.push_back(c);
                ++need_close;
            }
            else if (c == ')') {
                if (need_close == 0) {
                    invalid_close++;
                }
                else {
                    new_s.push_back(c);
                    need_close--;
                }
            }
            else {
                new_s.push_back(c);
            }
        }
        
        vector<char> output;
        
        int count = 0;
        for (int i = new_s.size() - 1; i >= 0; i--) {
            if (new_s[i] == ')') {
                ++count;
                output.push_back(')');
            }
            else if (new_s[i] == '(') {
                if (count > 0) {
                    output.push_back('(');
                    count--;
                }
            }
            else {
                output.push_back(new_s[i]);
            }
        } 
        
        string ans = "";
        
        for (int i = output.size() - 1; i >= 0; i--) {
            ans += output[i];
        }
        
        return ans;
    }
};


// Runtime: 40 ms, faster than 25.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 16 MB, less than 100.00% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// time complexity: O(n)
// space complexity: O(n)