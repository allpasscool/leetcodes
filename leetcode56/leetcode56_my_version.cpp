class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>> output;
        int start = -1, end = -1;
        
        for (int i = 0; i < intervals.size(); ++i) {
            // new interval start > end
            if (intervals[i][0] > end) {
                if (start != -1)
                    output.push_back(vector<int> {start, end});
                
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // new interval start <= end
            else if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
        }
        
        // if start != end != 0
        if (start != -1)   
           output.push_back(vector<int> {start, end});
        
        return output;
    }
    
    static bool comp(vector<int>& interval1, vector<int>& interval2) {
        return (interval1[0] < interval2[0]) 
            || (interval1[0] == interval2[0] && interval1[1] < interval2[1]);
    }
};

// Runtime: 16 ms, faster than 93.54% of C++ online submissions for Merge Intervals.
// Memory Usage: 12.3 MB, less than 100.00% of C++ online submissions for Merge Intervals.
// time complexity: O(n log n)
// space complexity: O(1)