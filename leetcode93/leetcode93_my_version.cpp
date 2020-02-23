class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<vector<int>> res;
        vector<int> cases(4);
        
        sp(s, res, cases, 0, 0);
        
        vector<string> ans;
        
        for (auto arr : res) {
            string tmp;
            
            for (int i = 0; i < 3; ++i) {
                tmp += to_string(arr[i]) + '.';
            }
            
            tmp += to_string(arr[3]);
            ans.push_back(tmp);
        }
        
        return ans;
    }
    
private:
    // split the ip
    void sp(string& s, vector<vector<int>>& res, vector<int> cur, int start, int section) {
        // cout << start << endl;
        if (section == 4 && start == s.length()) {
            res.push_back(cur);
            return;
        }
        else if (section >= 4) {
            return;
        }
        
        if (section == 3 && s.length() - start > 3) {
            return;
        }
        
        if (s[start] == '0') {
            cur[section] = 0;
            sp(s, res, cur, start + 1, section + 1);
            return;
        }
        
        for (int i = 0; i < 3 && start + i < s.length(); ++i) {
            // > 255
            int tmp = stoi(s.substr(start, i + 1));
            if (tmp > 255) {
                break;
            }
            else {
                cur[section] = tmp;
                sp(s, res, cur, start + i + 1, section + 1);
            }
        }
        
        return;
    }
};


// Runtime: 4 ms, faster than 68.43% of C++ online submissions for Restore IP Addresses.
// Memory Usage: 9.3 MB, less than 16.67% of C++ online submissions for Restore IP Addresses.
// time complexity: O(3^3) no more than 27 combinations
// space complexity: O(3 (recursive) + n (cur)) no more than 19 valid ip address