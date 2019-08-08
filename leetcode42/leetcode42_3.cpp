class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        
        for (current = 0; current < height.size(); current++) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                
                if (st.empty()) {
                    break;
                }
                
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                
                ans += distance * bounded_height;
            }
            st.push(current);
        }
        
        return ans;
    }
};
// Runtime: 8 ms, faster than 61.31% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.2 MB, less than 43.04% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(n)