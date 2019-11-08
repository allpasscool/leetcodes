class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;
        
        
        for (int i = 0; i < n; ++i) {
            if (target >= matrix[i][0] && target <= matrix[i][m - 1]
            && searchCol(matrix, target, i)) {
                return true;
            }
        }
        
        return false;
    }
private:
    bool searchCol(vector<vector<int>>& matrix, int target, int col) {
        int left = 0, right = matrix[0].size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (matrix[col][mid] == target) {
                return true;
            }
            else if (matrix[col][mid] < target) {
                left = mid + 1;
            }
            else if (matrix[col][mid] > target) {
                right = mid;
            }
        }
        
        return false;
    }
};


// Runtime: 112 ms, faster than 26.23% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix II.
// time complexity: O(n * log m)
// space complexity: O(1)