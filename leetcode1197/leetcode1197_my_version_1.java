class Solution {
    public int minKnightMoves(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        HashSet<String> visited = new HashSet<>();
        q.add(new int[]{0, 0});
        int count = 0;
        
        while (!q.isEmpty()) {
            int size = q.size();
            
            // spend count steps can reach these position
            for (int i = 0; i < size; i++) {
                int[] cur = q.poll();
                int cur_x = cur[0];
                int cur_y = cur[1];
                if (cur_x == x && cur_y == y)
                    return count;
                
                // visited before
                if (visited.contains(String.valueOf(cur_x) + "x" + String.valueOf(cur_y) + "y"))
                    continue;
                
                int distance = (cur_x - x) * (cur_x - x) + (cur_y - y) * (cur_y - y);
                if (distance > 100 && distance > x*x + y*y)
                    continue;
                // |x| + |y| <= 300
                if (Math.abs(cur_x) + Math.abs(cur_y) > 300)
                    continue;
                
                // first time
                visited.add(String.valueOf(cur_x) + "x" + String.valueOf(cur_y) + "y");
                
                // add next possible 8 pos
                q.add(new int[]{cur_x + 2, cur_y + 1});
                q.add(new int[]{cur_x + 1, cur_y + 2});
                q.add(new int[]{cur_x - 2, cur_y + 1});
                q.add(new int[]{cur_x - 1, cur_y + 2});
                q.add(new int[]{cur_x + 2, cur_y - 1});
                q.add(new int[]{cur_x + 1, cur_y - 2});
                q.add(new int[]{cur_x - 2, cur_y - 1});
                q.add(new int[]{cur_x - 1, cur_y - 2});
            }
            
            count++;
        }
        
        return -1;
    }
}

// Runtime: 1347 ms, faster than 5.00% of Java online submissions for Minimum Knight Moves.
// Memory Usage: 52.4 MB, less than 18.83% of Java online submissions for Minimum Knight Moves.
// time complexity: O(max(x^2, y^2))
// space complexity: O(max(x^2, y^2))