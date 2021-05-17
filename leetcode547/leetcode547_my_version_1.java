class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        int count = 0;
        
        // traverse all cities
        for (int i = 0; i < n; i++) {
            // checking all cities connected with city i
            for (int j = i; j < n; j++) {
                // haven't visited city j yet
                if (isConnected[i][j] == 1
                   && visited[j] == false) {
                    count++;
                    bfs(isConnected, visited, j);
                }
            }
        }
        
        return count;
    }
    
    private void bfs(int[][] isConnected, boolean[] visited, int j) {
        int n = isConnected.length;
        Queue<Integer> q = new LinkedList<>();
        // add j
        q.add(j);
        visited[j] = true;
        
        // visit all cities in this provinces
        while (!q.isEmpty()) {
            int city = q.poll();
            
            // visit all cites connected with 'city'
            for (int i = 0; i < n; i++) {
                if (isConnected[city][i] == 1
                   && visited[i] == false) {
                    q.add(i);
                    visited[i] = true;
                }
            }
        }
        
        return;
    }
}

// Runtime: 1 ms, faster than 68.27% of Java online submissions for Number of Provinces.
// Memory Usage: 39.8 MB, less than 64.49% of Java online submissions for Number of Provinces.
// time complexity: O(n * n) which there are n cities
// space complexity: O(n)