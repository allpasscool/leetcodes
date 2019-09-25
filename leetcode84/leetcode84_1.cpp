class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        
        for (int i = 0; i < heights.size(); ++i) {
            if (st.top() != -1 && heights[i] > heights[st.top()])
                st.push(i);
            else {
                while (st.top() != -1 && heights[i] <= heights[st.top()]) {
                    int top = st.top();
                    st.pop();
                    // height[top] has width st.top() which is where height is smaller than height[top] + 1 to i - 1
                    max_area = max(max_area, heights[top] * ((i - 1) - (st.top() + 1) + 1));
                }
                st.push(i);
            }
        }
        
        // all heights remains in stack has length from it to end of heights
        while (st.top() != -1) {
            int top = st.top();
            st.pop();
            max_area = max(max_area, heights[top] * ((int)heights.size() - (st.top() + 1)));
        }
        
        return max_area;
    }
};

// Runtime: 12 ms, faster than 86.68% of C++ online submissions for Largest Rectangle in Histogram.
// Memory Usage: 10.2 MB, less than 91.43% of C++ online submissions for Largest Rectangle in Histogram.
// time complexity: O(n)
// space complexity: O(n)