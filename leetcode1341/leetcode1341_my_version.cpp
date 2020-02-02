class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < mat.size(); ++i) {
            int soliders = 0;
            
            for (auto n : mat[i]) {
                soliders += n;
            }
            
            pq.push({soliders, i});
        }
        
        vector<int> output;
        
        for (int i = 0; i < k; ++i) {
            output.push_back(pq.top().second);
            pq.pop();
        }
        
        return output;
    }
};

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for The K Weakest Rows in a Matrix.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for The K Weakest Rows in a Matrix.
// time complexity: O(n log n)
// space complexity: O(n)