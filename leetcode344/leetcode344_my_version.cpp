class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int middle = n / 2;
        
        for (int i = 0; i < middle; i++) {
            swap(s[i], s[n - 1 - i]);
        }
        
        return;
    }
};

// Runtime: 44 ms, faster than 92.23% of C++ online submissions for Reverse String.
// Memory Usage: 15.2 MB, less than 96.34% of C++ online submissions for Reverse String.
// time complexity: O(n / 2)
// space complexity: O(1)