class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> covers;
        
        // O(n) reduction
        for (int i = 0; i < ranges.size(); ++i) {
            covers.push_back({max(0, i - ranges[i]), min(n, i + ranges[i])});
        }
        
        sort(covers.begin(), covers.end());
        
        // 1024. Video Stiching
        int ans = 0;
        int i = 0;
        int last = 0; // the farest start can be in this round
        int end = 0; // the farest start can be in next round
        
        while (end < n) {
            while (i <= n && covers[i].first <= last) {
                end = max(end, covers[i].second);
                ++i;
            }
            
            if (last == end) {
                return -1;
            }
            
            last = end;
            ++ans;
        }
        
        return ans;
    }
};


// Runtime: 24 ms, faster than 71.96% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Minimum Number of Taps to Open to Water a Garden.
// time complexity: O(n log n)
// space complexity: O(n)
// https://zxi.mytechroad.com/blog/greedy/leetcode-1326-minimum-number-of-taps-to-open-to-water-a-garden/