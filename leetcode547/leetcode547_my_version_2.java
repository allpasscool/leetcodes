class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        int count = 0;
        
        // traverse all cities
        for (int i = 0; i < n; i++) {
            // haven't visited city j yet
            if (visited[i] == false) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        
        return count;
    }
    
    private void dfs(int[][] isConnected, boolean[] visited, int j) {
        int n = isConnected.length;
        Stack<Integer> st = new Stack<>();
        // add j
        st.add(j);
        visited[j] = true;
        
        // visit all cities in this provinces
        while (!st.isEmpty()) {
            int city = st.pop();
            
            // visit all cites connected with 'city'
            for (int i = 0; i < n; i++) {
                if (isConnected[city][i] == 1
                   && visited[i] == false) {
                    st.add(i);
                    visited[i] = true;
                }
            }
        }
        
        return;
    }
}

// Runtime: 1 ms, faster than 68.27% of Java online submissions for Number of Provinces.
// Memory Usage: 39.9 MB, less than 51.35% of Java online submissions for Number of Provinces.
// time complexity: O(n * n) which there are n cities
// space complexity: O(n)