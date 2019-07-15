class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        int end = 0;
        
        for(int i = 0; i < strs[0].length(); i++){
            
            for(int j = 0; j < strs.size(); j++){
                if(strs[j].length() <= i || strs[0][i] != strs[j][i]){
                    return strs[0].substr(0, i);
                }
            }
            end = i;
        }
        
        //common prefix
        return strs[0].substr(0, (end+1));
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 8.7 MB, less than 81.43% of C++ online submissions for Longest Common Prefix.
// time complexity: O(n * m). n is the size of vector strs, and m is the shortest string in the vector
// space complexity: O(1)