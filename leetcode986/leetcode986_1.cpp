class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int counter1 = 0, counter2 = 0;
        vector<vector<int>> ans;
        
        while (counter1 < A.size() && counter2 < B.size()) {
            int lo = max(A[counter1][0], B[counter2][0]);
            int hi = min(A[counter1][1], B[counter2][1]);
            
            if (lo <= hi) 
                ans.push_back({lo, hi});
            
            if (A[counter1][1] < B[counter2][1])
                ++counter1;
            else
                ++counter2;
        }
        
        return ans;
    }
};


// Runtime: 48 ms, faster than 91.05% of C++ online submissions for Interval List Intersections.
// Memory Usage: 15.8 MB, less than 80.00% of C++ online submissions for Interval List Intersections.
// time complexity: O(m + n)
// space complexity: O(1)