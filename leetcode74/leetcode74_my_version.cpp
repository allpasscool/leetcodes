class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        
        int row = selectRow(matrix, target);
        // cout << "row: " << row << endl;
        
        // bigger than all nums
        if (row >= m)
            return false;
        
        return searchCol(matrix, target, row);
        // return false;
    }
    
private:
    int selectRow(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size();
        int n = matrix[0].size();
        
        while (up < down) {
            int mid = up + (down - up) / 2;
            // cout << up << " , " << down << " , " << mid << endl;
            
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                return mid;
            }
            else if (target < matrix[mid][0]) {
                down = mid;
            }
            else if (target > matrix[mid][n - 1]) {
                up = mid + 1;
            }
        }
        
        return up;
    }
    
    bool searchCol(vector<vector<int>>& matrix, int target, int row) {
        int left = 0, right = matrix[0].size();
        int mid;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            // cout << left << " , " << right << " , " << mid << endl;
            
            if (matrix[row][mid] == target) {
                return true;
            }
            else if (matrix[row][mid] < target) {
                left = mid + 1;
            }
            else if (matrix[row][mid] > target) {
                right = mid;
            }
        }
        
        // cout << mid << endl;
        return false;
    }
};

// Runtime: 8 ms, faster than 93.72% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.
// time complexity: O(log n * log m)
// space complexity: O(1)