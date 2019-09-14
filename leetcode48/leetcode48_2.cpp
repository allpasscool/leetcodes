class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n / 2 + n % 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                vector<int> tmp(4, 0);
                int row = i;
                int col = j;
                cout << i << ", " << j << endl;
                
                for (int k = 0; k < 4; k++) {
                    tmp[k] = matrix[row][col];
                    int x = row;
                    row = col;
                    col = n - 1 - x;
                }
                
                for (int k = 0; k < 4; k++) {
                    matrix[row][col] = tmp[(k + 3) % 4];
                    int x = row;
                    row = col;
                    col = n - 1 - x;
                }
            }
        }
    }
};
// Runtime: 4 ms, faster than 81.66% of C++ online submissions for Rotate Image.
// Memory Usage: 9.1 MB, less than 68.29% of C++ online submissions for Rotate Image.
// time complexity: O(n^2)
// space complexity: O(1)