class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        for (int i = 0; i < points.size(); ++i) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < K; ++i) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return ans;
    }
};

// Runtime: 232 ms, faster than 77.90% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 42.2 MB, less than 67.19% of C++ online submissions for K Closest Points to Origin.
// time complexity: O(k log n)
// space complexity: O(n)