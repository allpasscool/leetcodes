class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    rows.push_back(row);
                    cols.push_back(col);
                }
            }
        }
        
        int row = rows[rows.size() / 2];
        sort(cols.begin(), cols.end());
        int col = cols[cols.size() / 2];
        
        return minDistance1D(rows, row) + minDistance1D(cols, col);
    }
    
private:
    int minDistance1D(vector<int>& points, int origin) {
        int dis = 0;
        
        for (int point: points) {
            dis += abs(point - origin);
        }
        
        return dis;
    }
};

// Runtime: 8 ms, faster than 70.65% of C++ online submissions for Best Meeting Point.
// Memory Usage: 10 MB, less than 66.67% of C++ online submissions for Best Meeting Point.
// time complexity: O(mn log mn)
// space complexity: O(mn)