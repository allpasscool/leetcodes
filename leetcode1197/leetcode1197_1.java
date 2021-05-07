class Solution {
    private final int[][] DIRECTIONS = new int[][] {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    public int minKnightMoves(int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);
        
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] {0, 0});
        
        Set<String> visited = new HashSet<>();
        visited.add("0,0");
        
        int result = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.remove();
                int curX = cur[0];
                int curY = cur[1];
                if (curX == x && curY == y) {
                    return result;
                }
                
                for (int[] d : DIRECTIONS) {
                    int newX = curX + d[0];
                    int newY = curY + d[1];
                    if (!visited.contains(newX + "," + newY) && newX >= -1 && newY >= -1) {
                        queue.add(new int[] {newX, newY});
                        visited.add(newX + "," + newY);
                    }
                }
            }
            result++;
        }
        return -1;
    }
}

// https://leetcode.com/problems/minimum-knight-moves/discuss/401580/Clean-Java-BFS-solution
// Runtime: 618 ms, faster than 22.51% of Java online submissions for Minimum Knight Moves.
// Memory Usage: 49.2 MB, less than 33.80% of Java online submissions for Minimum Knight Moves.
// time complexity: O(max(x^2, y^2))
// space complexity: O(max(x^2, y^2))
// I guess the goal should be to first get an agreement on the approach (in this case BFS). 
// Then you could code an almost correct BFS solution that would in theory give you a right answer (even though it may timeout in the OJ here).
// The interviewer at this point may hint that this solution will take too long to run and you start looking at how to optimize it. 
// You realize that you can only stick to the first quadrant and you add the x >= 0 y >= 0 condition. 
// The interviewer probably knows this will work for all but (1,1) 
// and asks you to come up with few test cases (or even better gives you the test case (1,1) as input) 
// and you eventually realize that your condition should be x >= -1 y >= -1.
// In my opinion, this shows that you can code a right solution using an acceptable approach 
// and can take hints/collaborate and make it 100% correct and this is still achievable to do in 15 - 20 mins.