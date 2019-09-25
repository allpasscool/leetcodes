class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int ny = matrix.size();
        vector<int> output;
        if (ny == 0) {
            return output;
        }
        
        int nx = matrix[0].size();
        output = vector<int> (ny * nx, 0);
        vector<vector<bool>> visited(ny, vector<bool> (nx, false));
        vector<int> dr = {0, 1, 0, -1}; // direction of row
        vector<int> dc = {1, 0, -1, 0}; // direction of column
        int r = 0, c = 0, di = 0; // di is direction i
        
        for (int i = 0; i < ny * nx; ++i) {
            // cout << r << ", " << c << endl;
            output[i] = matrix[r][c];
            visited[r][c] = true;
            
            int next_r = r + dr[di];
            int next_c = c + dc[di];
            
            if (next_r >= 0 && next_r < ny 
                && next_c >= 0 && next_c < nx
               && !visited[next_r][next_c]) {
                r = next_r;
                c = next_c;
            }
            // next r and c in this direction has been visited or is invalid
            // change direction
            else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        
        return output;
    }
};

// Runtime: 4 ms, faster than 57.59% of C++ online submissions for Spiral Matrix.
// Memory Usage: 8.7 MB, less than 69.70% of C++ online submissions for Spiral Matrix.
// time complexity: O(nx * ny)
// space complexity: O(nx * ny)