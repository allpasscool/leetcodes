class Solution {
    public int trap(int[] height) {
        int volume = 0, cur = 0;
        Stack<Integer> st = new Stack<>();
        
        while (cur < height.length)
        {
            while (!st.empty() && height[cur] > height[st.peek()])
            {
                int top = st.pop();
                // no left bound
                if (st.empty())
                    break;
                // distance = rightbound - leftbound - 1
                int distance = cur - st.peek() - 1;
                // height is min(rightbound, leftbound) - height[top]
                int boundedHeight = Math.min(height[cur], height[st.peek()]) - height[top];
                volume += distance * boundedHeight;
            }
            st.push(cur);
            cur++;
        }
        
        return volume;
    }
}

// Runtime: 3 ms, faster than 18.31% of Java online submissions for Trapping Rain Water.
// Memory Usage: 38.9 MB, less than 25.90% of Java online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(n)