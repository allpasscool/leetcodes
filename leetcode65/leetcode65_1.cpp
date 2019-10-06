class Solution {
public:
    bool isNumber(string s) {
        int i = 0;

        // skip the whilespaces
        while (s[i] == ' ')
            ++i;
        
        // check the significand
        if(s[i] == '+' || s[i] == '-') ++i; // skip the sign if exist

        int n_nm, n_pt;
        for(n_nm = 0, n_pt = 0; isdigit(s[i]) || s[i] == '.'; i++)
            s[i] == '.' ? ++n_pt : ++n_nm;       
        
        if(n_pt > 1 || n_nm < 1) // no more than one point, at least one digit
            return false;

        // check the exponent if exist
        if(s[i] == 'e') {
            ++i;
            
            if(s[i] == '+' || s[i] == '-') 
                ++i; // skip the sign

            int n_nm = 0;
            while (isdigit(s[i])) {
                ++i;
                ++n_nm;
            }
            
            if(n_nm < 1)
                return false;
        }

        // skip the trailing whitespaces
        while (s[i] == ' ')
            ++i;

        return s[i] == 0;  // must reach the ending 0 of the string
    }
};

// Runtime: 4 ms, faster than 74.73% of C++ online submissions for Valid Number.
// Memory Usage: 8.1 MB, less than 80.00% of C++ online submissions for Valid Number.
// time complexity: O(n)
// space complexity: O(1)