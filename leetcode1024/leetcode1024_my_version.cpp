class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), comp);
        
        vector<int> dp(T + 1, INT_MAX);
        if (clips[0][0] != 0) {
            return -1;
        }
        else {
            for (int i = clips[0][0]; i <= clips[0][1] && i <= T; ++i) {
                dp[i] = 1;
            }
        }
        
        
        for (int i = 1; i < clips.size(); ++i) {
            int start = clips[i][0];
            int end = clips[i][1];
            
            if (start >= T) {
                return dp[T] == INT_MAX ? -1 : dp[T];
            }
            
            if (dp[start] == INT_MAX) {
                return -1;
            }
            else {
                for (int j = start + 1; j <= end && j <= T; ++j) {
                    dp[j] = min(dp[start] + 1, dp[j]);
                }
            }
        }
        
        return dp[T] == INT_MAX ? -1 : dp[T];
    }
private:
    static bool comp(vector<int>& left, vector<int>& right) {
        return (left[0] < right[0]) || (left[0] == right[0] && left[1] > right[1]);
    }
};


// Runtime: 4 ms, faster than 71.71% of C++ online submissions for Video Stitching.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Video Stitching.
// time complexity: O(n * m + n log n), n is #of clips, m is the longest clip
// space complexity: O(T)