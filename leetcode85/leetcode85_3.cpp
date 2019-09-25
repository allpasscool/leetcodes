class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ny = matrix.size();
        if (ny == 0)
            return 0;
        
        int nx = matrix[0].size();
        // initialize left as the left most boundary possible
        vector<int> left(nx, 0);
        // initialize right as the right most boundary
        vector<int> right(nx, nx);
        vector<int> height(nx, 0);
        
        int max_area = 0;
        
        for (int i = 0; i < ny; ++i) {
            int cur_left = 0, cur_right = nx;
            
            // update height
            for (int j = 0; j < nx; ++j) {
                if (matrix[i][j] == '1')
                    ++height[j];
                else
                    height[j] = 0;
            }
            
            // update left
            for (int j = 0; j < nx; ++j) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }   
            }
            
            // update right
            for (int j = nx - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else {
                    right[j] = nx;
                    cur_right = j;
                }
            }
            
            //update area
            for (int j = 0; j < nx; ++j)
                max_area = max(max_area, (right[j] - left[j]) * height[j]);
        }
        
        return max_area;
    }
};
// class Solution {public:
// int maximalRectangle(vector<vector<char> > &matrix) {
//     if(matrix.empty()) return 0;
//     const int m = matrix.size();
//     const int n = matrix[0].size();
//     int left[n], right[n], height[n];
//     fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
//     int maxA = 0;
//     for(int i=0; i<m; i++) {
//         int cur_left=0, cur_right=n; 
//         for(int j=0; j<n; j++) { // compute height (can do this from either side)
//             if(matrix[i][j]=='1') height[j]++; 
//             else height[j]=0;
//         }
//         for(int j=0; j<n; j++) { // compute left (from left to right)
//             if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
//             else {left[j]=0; cur_left=j+1;}
//         }
//         // compute right (from right to left)
//         for(int j=n-1; j>=0; j--) {
//             if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
//             else {right[j]=n; cur_right=j;}    
//         }
//         // compute the area of rectangle (can do this from either side)
//         for(int j=0; j<n; j++)
//             maxA = max(maxA,(right[j]-left[j])*height[j]);
//     }
//     return maxA;
// }
// };

// Runtime: 20 ms, faster than 94.01% of C++ online submissions for Maximal Rectangle.
// Memory Usage: 10.4 MB, less than 100.00% of C++ online submissions for Maximal Rectangle.
// time complexity: O(NM), N is number of row, M is row of column
// space complexity:O(M)