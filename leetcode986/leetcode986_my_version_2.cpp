class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int counter1 = 0, counter2 = 0;
        vector<vector<int>> ans;
        
        while (counter1 < A.size() && counter2 < B.size()) {
            
            // no intersection, A < B
            while (counter1 < A.size() &&
                   A[counter1][1] < B[counter2][0]) {
                ++counter1;
            }
            if (counter1 >= A.size()) {
                break;
            }
            
            // no intersection, A < B
            if (B[counter2][1] < A[counter1][0]) {
                while (counter2 < B.size() && B[counter2][1] < A[counter1][0]) {
                    ++counter2;
                }
                if (counter2 >= B.size()) {
                    return ans;
                }
                continue;
            }
            
            
            // with intersection
            int start, end;
            start = max(A[counter1][0], B[counter2][0]);
            end = min(A[counter1][1], B[counter2][1]);
            
            ans.push_back({start, end});
            
            if (A[counter1][1] < B[counter2][1]) {
                ++counter1;
            }
            else if (B[counter2][1] < A[counter1][1]) {
                ++counter2;
            }
            else {
                ++counter1;
                ++counter2;
            }
            
        }
        
        return ans;
    }
};


// Runtime: 48 ms, faster than 91.05% of C++ online submissions for Interval List Intersections.
// Memory Usage: 15.8 MB, less than 80.00% of C++ online submissions for Interval List Intersections.
// time complexity: O(n)
// space complexity: O(1)