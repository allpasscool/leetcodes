class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int max_substr_len = end - start;
        
        for(int i = 0; i < s.size(); i++){//start
            for(int j = s.size() - 1; (j - i) > max_substr_len; j--){//end
                int start_sub = i, end_sub = j;//substring start and end
                //int max_substr_len = end - start;
                
                if(s.size() - i < max_substr_len){// got max palindromic substr
                    return s.substr(start, (end - start + 1));
                }
                
                while(true){//find palindromic substring
                    
                    if(s[start_sub] != s[end_sub]){//doesn't match
                        break;
                    }
                    
                    if(end_sub - start_sub == 0 || end_sub - start_sub == 1){//got palindromic substr
                        end = j;
                        start = i;
                        max_substr_len = end - start;
                        break;
                    }
                    
                    start_sub++;
                    end_sub--;
                }
            }
        }
    
    return s.substr(start, (end - start + 1));
    }
};
// Runtime: 204 ms, faster than 20.88% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 8.7 MB, less than 85.58% of C++ online submissions for Longest Palindromic Substring.
//time complexity: O(n^3)
//space complexity: O(1)