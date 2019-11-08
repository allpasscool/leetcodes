class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // an empty matrix obviously doesn't contain 'target'
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        // iterate over matrix diagonals
        int shorterDim = min(matrix.size(), matrix[0].size());
        for (int i = 0; i < shorterDim; ++i) {
            bool verticalFound = binarySearch(matrix, target, i, true);
            bool horizontalFound = binarySearch(matrix, target, i, false);
            
            if (verticalFound || horizontalFound) {
                return true;
            }
        }
        
        return false;
    }
private:
    bool binarySearch(vector<vector<int>>& matrix, int target, int start, bool vertical) {
        int lo = start;
        int hi = vertical ? matrix[0].size() - 1 : matrix.size() - 1;
        
        while (hi >= lo) {
            int mid = (lo + hi) / 2;
            
            if (vertical) { // searching a column
                if (matrix[start][mid] < target) {
                    lo = mid + 1;
                }
                else if (matrix[start][mid] > target) {
                    hi = mid - 1;
                }
                else {
                    return true;
                }
            }
            else { // searching a row
                if (matrix[mid][start] < target) {
                    lo = mid + 1;
                }
                else if (matrix[mid][start] > target) {
                    hi = mid - 1;
                }
                else {
                    return true;
                }
            }
        }
        
        return false;
    }
};


// Runtime: 224 ms, faster than 13.98% of C++ online submissions for Search a 2D Matrix II.
// Memory Usage: 12.8 MB, less than 91.11% of C++ online submissions for Search a 2D Matrix II.
// time complexity: O(log (n!))
// space complexity: O(1)