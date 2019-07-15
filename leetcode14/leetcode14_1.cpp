class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        string prefix = strs[0];
        
        for(int i = 1; i < strs.size(); i++){
            int j;
            for(j = 0; j < strs[i].length() && j < prefix.length(); j++){
                if(strs[i][j] != prefix[j]){
                    break;
                }
            }
            prefix = prefix.substr(0, j);
        }
        
        return prefix;
    }
};
// Runtime: 4 ms, faster than 96.31% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 8.9 MB, less than 29.97% of C++ online submissions for Longest Common Prefix.
// time complexity: O(n * m). n is the size of vector strs, and m is the shortest string in the vector
// space complexity: O(1), only use constant space