class Solution {
public:
    bool isNumber(string s) {
        int state = 0, flag = 0; // flag to judge the special case "."
        
        while (s[0] == ' ')  
            s.erase(0, 1);//delete the  prefix whitespace 
        
        while(s[s.length() - 1] == ' ') 
            s.erase(s.length()-1, 1);//delete the suffix whitespace
        
        for(int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])){
                flag = 1;
                if (state <= 2) 
                    state = 2;
                else 
                    state = (state <= 5) ? 5 : 7;
            }
            else if ('+' == s[i] || '-' == s[i]) {
                if (state == 0 || state == 3) 
                    ++state;
                else 
                    return false;
            }
            else if ('.' == s[i]) {
                if (state <= 2) 
                    state = 6;
                else
                    return false;
            }
            else if('e' ==s [i]) {
                if (flag && 
                    (state == 2 || state == 6 || state == 7))
                    state = 3;
                else
                    return false;
            }
            else
                return false;
        }
        return (state == 2 || state == 5 
                || (flag && state == 6) || state == 7);
    }
};

// Runtime: 8 ms, faster than 30.34% of C++ online submissions for Valid Number.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Valid Number.
// time complexity: O(n)
// space complexity: O(1)

// There are 5 kind of inputs in my DFA:
// digit : number 0-9 for
// +,- : operator + or -(negative or positive)
// exp: e
// dot: .
// other: you can return false Immediately
// 4 final States in my DFA transition diagram : s2, s6, s7, s8
// If the state change to final state at last, return true.
// s2 can accept digits only : +1 -23432 123 and etc
// s5 can accept exp expression: +2.4e+12 3e9 and etc
// s6 can accept decimals end with dot: 1. -42. and etc
// (careful, what if there exist only one dot "."
// **** I use a variable flag judging weather there existing numbers. cause 0. and .0 is valid and . is invalid ****
// )
// s7 can accept decimals: +12.23, 87., 132
// https://leetcode.com/problems/valid-number/discuss/23725/C%2B%2B-My-thought-with-DFA