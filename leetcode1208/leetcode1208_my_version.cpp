class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        if (n == 0)
            return 0;
        
        int max_length = 0;
        // vector<int> diff(n, 0);
        
        int left = 0, right = 0;
        int cur_max = 0;
        
        while (right < n) {
            cur_max += (int)abs(t[right] - s[right]);
            if (cur_max <= maxCost) {
                max_length = max(max_length, right - left + 1);
            }
            else {
                while (cur_max > maxCost) {
                    cur_max -= (int)abs(t[left] - s[left]);
                    ++left;
                }
                max_length = max(max_length, right - left + 1);
            }
            ++right;
        }
        
        return max_length;
    }
};

// Runtime: 12 ms, faster than 84.46% of C++ online submissions for Get Equal Substrings Within Budget.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Get Equal Substrings Within Budget.
// time complexity: O(n)
// space complexity: O(1)