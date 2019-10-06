class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        if (arr.size() <= 1)
            return arr.size();
        
        int sublong = 1;
        int n = arr.size();
        unordered_map<int, int> hashmap; // key is arr[i], value is len;
        
        for (int i = 0; i < n; ++i) {
            hashmap[arr[i]] = 1 + hashmap[arr[i] - difference];
            sublong = max(sublong, hashmap[arr[i]]);
        }
        
        return sublong;
    }
};
// Runtime: 160 ms, faster than 100.00% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
// Memory Usage: 23.4 MB, less than 100.00% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
// time complexity: O(n)
// space complexity: O(n)