class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        // sort trips by pickup pos. If pickup pos is equal, then sort by drop pos
        Arrays.sort(trips, (a, b) -> (a[1] == b[1]) ? a[2] - b[2] : a[1] - b[1]);
        
        PriorityQueue<int[]> nextDrop = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        int curCap = capacity;
        int curTrip = 0;
        int nextStop = 0;
        
        while (curTrip < trips.length)
        {
            // Drop
            if (!nextDrop.isEmpty() && nextDrop.peek()[2] <= trips[curTrip][1])
            {
                curCap += nextDrop.poll()[0];
            }
            // pickup
            else
            {
                curCap -= trips[curTrip][0];
                
                // over cap?
                if (curCap < 0)
                    return false;
                
                nextDrop.offer(trips[curTrip]);
                curTrip++;
            }
            
        }
        
        
        return true;
    }
}

// Runtime: 11 ms, faster than 14.36% of Java online submissions for Car Pooling.
// Memory Usage: 41.6 MB, less than 14.26% of Java online submissions for Car Pooling.
// time complexity: O(n log n)
// space complexity: O(n)