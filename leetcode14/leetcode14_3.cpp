class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        int min_len = INT_MAX;
        for(int i = 0; i < strs.size(); i++){
            min_len = std::min(min_len, (int)strs[i].length());
        }
        
        int low = 1, high = min_len;
        
        while(low <= high){
            int middle = (low + high) / 2;
            
            if(isCommonPrefix(strs, middle)){
                low = middle + 1;
            }
            else{
                high = middle - 1;
            }
        }
        
        return strs[0].substr(0, (low + high) / 2);
    }
    
private:
    bool isCommonPrefix(vector<string>& strs, int len){
        string str_left = strs[0].substr(0, len);
        
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].length() < str_left.length()){
                return false;
            }
            for(int j = 0; j < str_left.length(); j++){
                if(str_left[j] != strs[i][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
};
// Runtime: 4 ms, faster than 96.31% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 8.7 MB, less than 85.06% of C++ online submissions for Longest Common Prefix.
// time complexity: O(m * n * log n) n equal strings with length m
// space complexity: O(1)