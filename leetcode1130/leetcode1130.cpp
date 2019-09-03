class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            return 0;
        }
        
        stack<int> st;
        int cost = 0;
        
        st.push(INT_MAX);
        
        for (int i = 0; i < n; i++) {
            while (st.top() <= arr[i]) {
                int tmp = st.top();
                st.pop();
                cost += tmp * min(st.top(), arr[i]);
            }
            
            st.push(arr[i]);
        }
        
        while (st.size() > 2) {
            int tmp = st.top();
            st.pop();
            cost += st.top() * tmp;
        }
        
        return cost;
    }
};
// Runtime: 4 ms, faster than 80.62% of C++ online submissions for Minimum Cost Tree From Leaf Values.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Minimum Cost Tree From Leaf Values.
// time complexity: O(n)
// space complexity: O(n)