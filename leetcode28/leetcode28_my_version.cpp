class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0){
            return 0;
        }
        
        int last_start = haystack.length() - needle.length();
        int j;
        
        for(int i = 0; i <= last_start; i++){
            for(j = 0; j < needle.length(); j++){
                if(haystack[i + j] != needle[j]){
                    break;
                } else if(j == (needle.length() - 1)){
                    return i;
                }
            }
        }
        
        return -1;
    }
};
// Runtime: 4 ms, faster than 92.49% of C++ online submissions for Implement strStr().
// Memory Usage: 9 MB, less than 75.28% of C++ online submissions for Implement strStr().
// time complexity: O(n * m), n is the length of haystack, m is the length of needle
// space complexity: O(1)