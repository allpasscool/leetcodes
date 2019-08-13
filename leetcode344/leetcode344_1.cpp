class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
        
        return;
    }
};

// Runtime: 44 ms, faster than 92.23% of C++ online submissions for Reverse String.
// Memory Usage: 15.3 MB, less than 70.73% of C++ online submissions for Reverse String.
// time complexity: O(n)
// space complexity: O(1)