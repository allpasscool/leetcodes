class Solution {
public:
    string longestPalindrome(string s) {
        //empty string
        if(s.size() < 1){ return "";}
        
        int start = 0, end = 0, max_len = 1;
        
        for(int i = 0; i < s.size(); i++){
            if(i + (max_len / 2) >= s.size()){
                break;
            }
            
            // int len1 = expandAroundCenter(s, i, i);
            // int len2 = expandAroundCenter(s, i, i+1);
            int len1 = 0, len2 = 0;
            int L = i, R = i;
            while(L >= 0 && R < s.size() && s[L] == s[R]){
                L--;
                R++;
            }
            len1 = R - L - 1;
            
            L = i, R = i+1;
            while(L >= 0 && R < s.size() && s[L] == s[R]){
                L--;
                R++;
            }
            len2 = R - L - 1;
            
            int len = std::max(len1, len2);
            
            if(len > max_len){
                start = i - (len - 1) / 2;
                end = i + len / 2;
                max_len = len;
            }
        }
        
        return s.substr(start, (end-start+1));
    }
};
// Runtime: 12 ms, faster than 85.91% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 8.8 MB, less than 72.61% of C++ online submissions for Longest Palindromic Substring.
// Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
// Space complexity : O(1). 