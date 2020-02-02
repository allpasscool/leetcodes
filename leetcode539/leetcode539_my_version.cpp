class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times(timePoints.size());
        
        for (int i = 0; i < timePoints.size(); ++i) {
            auto& t = timePoints[i];
            
            int time = stoi(t.substr(0, 2)) * 60 +stoi(t.substr(3, 2));
            
            times[i] = time;
        }
        
        sort(times.begin(), times.end());
        
        int ans = INT_MAX;
        for (int i = 1; i < times.size(); ++i) {
            ans = min(ans, times[i] - times[i - 1]);
        }
        
        if (times[0] < times.back()) {
            ans = min(ans, times[0] - (times.back() - (24 * 60)));
        }
        else {
            ans = min(ans, times.back() - (times[0] - (24 * 60)));
        }
        
        return ans;
    }
};


// Runtime: 20 ms, faster than 71.63% of C++ online submissions for Minimum Time Difference.
// Memory Usage: 11.9 MB, less than 80.00% of C++ online submissions for Minimum Time Difference.
// time complexity: O(n log n)
// space complexity: O(n)