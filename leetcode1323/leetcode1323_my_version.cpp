class Solution {
public:
    int maximum69Number (int num) {
        string num_s = to_string(num);
        
        for (int i = 0; i < num_s.length(); ++i) {
            if (num_s[i] == '6') {
                num_s[i] = '9';
                break;
            }
        }
        
        return stoi(num_s);
    }
};


// Runtime: 4 ms, faster than 55.39% of C++ online submissions for Maximum 69 Number.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Maximum 69 Number.
// time complexity: O(n)
// space complexity: O(1)