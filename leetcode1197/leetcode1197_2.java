class Solution {
    public int minKnightMoves(int x, int y) {
        // the offsets in the eight directions
        int[][] directions = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        // data structures needed to move from the origin point
        // origin Queue
        Queue<int[]> originQ = new LinkedList<>();
        // [x, y, steps]
        originQ.add(new int[]{0, 0, 0});
        // origin distance
        Map<String, Integer> originD = new HashMap<>();
        // key = x,y value = steps
        originD.put("0,0", 0);

        // data structures needed to move from the target point
        // target queue
        Queue<int[]> targetQ = new LinkedList<>();
        // [x, y, steps]
        targetQ.add(new int[]{x, y, 0});
        // target distance
        Map<String, Integer> targetD = new HashMap<>();
        // key = x,y value = steps
        targetD.put(x + "," + y, 0);

        while (true) {
            // check if we reach the circle of target
            int[] origin = originQ.poll();
            int oX = origin[0], oY = origin[1], oSteps = origin[2];
            String originXY = oX + "," + oY;
            
            if (targetD.containsKey(originXY)) {
                return oSteps + targetD.get(originXY);
            }

            // check if we reach the circle of origin
            int[] target = targetQ.poll();
            int tX = target[0], tY = target[1], tSteps = target[2];
            String targetXY = tX + "," + tY;
            if (originD.containsKey(targetXY)) {
                return tSteps + originD.get(targetXY);
            }

            for (int[] dir : directions) {
                // expand the circle of origin
                // int[] nextOrigin = new int[]{oX + dir[0], oY + dir[1]};
                int nextOX = oX + dir[0], nextOY = oY + dir[1], nextOSteps = oSteps + 1;
                String nextOriginXY = nextOX + "," + nextOY;
                if (!originD.containsKey(nextOriginXY)) {
                    originQ.add(new int[]{nextOX, nextOY, nextOSteps});
                    originD.put(nextOriginXY, nextOSteps);
                }

                // expand the circle of target
                int nextTX = tX + dir[0], nextTY = tY + dir[1], nextTSteps = tSteps + 1;
                // int[] nextTarget = new int[]{target[0] + dir[0], target[1] + dir[1]};
                String nextTargetXY = nextTX + "," + nextTY;
                if (!targetD.containsKey(nextTargetXY)) {
                    targetQ.add(new int[]{nextTX, nextTY, nextTSteps});
                    targetD.put(nextTargetXY, nextTSteps);
                }
            }
        }
    }
}

// Runtime: 1218 ms, faster than 6.43% of Java online submissions for Minimum Knight Moves.
// Memory Usage: 61.9 MB, less than 10.91% of Java online submissions for Minimum Knight Moves.
// time complexity: O(max(x^2, y^2))
// space complexity: O(max(x^2, y^2))