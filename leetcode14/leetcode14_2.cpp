class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
private:
    string longestCommonPrefix(vector<string>& strs, int left, int right){
        if(left == right){
            return strs[left];
        }
        else{
            int mid = (left + right) / 2;
            string lcp_left = longestCommonPrefix(strs, left, mid);
            string lcp_right = longestCommonPrefix(strs, mid + 1, right);
            return commonPrefix(lcp_left, lcp_right);
        }
    }
    
    string commonPrefix(string str_left, string str_right){
        int min = std::min(str_left.length(), str_right.length());
        for(int i = 0; i < min; i++){
            if(str_left[i] != str_right[i]){
                return str_left.substr(0, i);
            }
        }
        return str_left.substr(0, min);
    }
};
Runtime: 4 ms, faster than 96.31% of C++ online submissions for Longest Common Prefix.
Memory Usage: 12.2 MB, less than 6.68% of C++ online submissions for Longest Common Prefix.
time complexity: O(m * n) , n equal strings with length m
space complexity: O(m log n) There are log n recursive calls, each store need m space to store the result,