class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ny = matrix.size();
        if (ny == 0)
            return 0;
        
        int nx = matrix[0].size();
        int max_area = 0;
        vector<int> dp(nx, 0);
        
        // each row
        for (int i = 0; i < ny; ++i) {
            // each column
            for (int j = 0; j < nx; ++j) {
                // update the state of this row's histogram using the last row's histogram
                // by keeping track of the number of consecutive ones
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update max area with the maximum area from this row's histogram
            max_area = max(max_area, leetcode84(dp));
        }
        
        return max_area;
    }
    
    int leetcode84(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                int top = st.top();
                st.pop();
                max_area = max(max_area, heights[top] * (i - st.top() - 1));
            }
            st.push(i);
        }
        
        // after reach end of heights
        while (st.top() != -1) {
            int top = st.top();
            st.pop();
            max_area = max(max_area, heights[top] * ((int)heights.size() - st.top() - 1));
        }
        
        return max_area;
    }
};

// Runtime: 28 ms, faster than 38.13% of C++ online submissions for Maximal Rectangle.
// Memory Usage: 11.4 MB, less than 55.56% of C++ online submissions for Maximal Rectangle.
// time complexity: O(NM), leetcode84 on each row takes O(M), (length of each row), This is done N times for O(NM)
// space complexity: O(M), dp for the row