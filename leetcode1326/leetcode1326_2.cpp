class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jump(n + 1); // jump[i] = j, pos i can jump to j
        
        // O(n) reduction
        for (int i = 0; i < ranges.size(); ++i) {
            int start = max(0, i - ranges[i]);
            
            jump[start] = max(jump[start], i + ranges[i]);
        }
        
        // 45. Jump Game II
        int ans = 0;
        int last = 0; // the farest start in this round
        int end = 0; // the farest start in next round
        
        for (int i = 0; i <= n; ++i) {
            // can't cover end to i
            if (i > end) {
                return -1;
            }
            if (i > last) {
                last = end;
                ++ans;
            }
            
            end = max(end, jump[i]);
        }
        
        return ans;
    }
};


// Runtime: 20 ms, faster than 83.20% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
// Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
// time complexity: O(n)
// space complexity: O(n)
// https://zxi.mytechroad.com/blog/greedy/leetcode-1326-minimum-number-of-taps-to-open-to-water-a-garden/
