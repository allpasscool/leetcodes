class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> times(24 * 60);
        
        for (int i = 0; i < timePoints.size(); ++i) {
            auto& t = timePoints[i];
            
            int time = stoi(t.substr(0, 2)) * 60 +stoi(t.substr(3, 2));
            
            if (times[time]) {
                return 0;
            }
            
            times[time] = true;
        }
        
        int prev = -1;
        int ans = INT_MAX;
        int first = INT_MAX, last = INT_MIN;
        
        for (int i = 0; i < 24 * 60; ++i) {
            if (times[i]) {
                if (first != INT_MAX) {
                    ans = min(ans, i - prev);
                }
                
                first = min(first, i);
                last = max(last, i);
                prev = i;
            }
        }
        
        ans = min(ans, first + 24 * 60 - last);
        
        return ans;
    }
};


// Runtime: 16 ms, faster than 91.51% of C++ online submissions for Minimum Time Difference.
// Memory Usage: 11.7 MB, less than 80.00% of C++ online submissions for Minimum Time Difference.
// time complexity: O(n)
// space complexity: O(1)