class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st = new Stack<>();
        int n = temperatures.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            if (st.isEmpty() || temperatures[i] <= temperatures[st.peek()]) {
                st.push(i);
            }
            // warmer than before
            else {
                while (!st.isEmpty() && temperatures[st.peek()] < temperatures[i]) {
                    ans[st.peek()] = i - st.peek();
                    st.pop();
                }
                st.push(i);
            }
        }

        return ans;
    }
}

// Runtime: 42 ms, faster than 26.54% of Java online submissions for Daily
// Temperatures.
// Memory Usage: 49.1 MB, less than 22.34% of Java online submissions for Daily
// Temperatures.
// time complexity: O(n)
// space complexity: O(n)