class Solution {
    public int[][] merge(int[][] intervals) {
        // sort by start time
        // if start time are same, then sort by end time
        Arrays.sort(intervals,
                   (int[] i1, int[] i2) -> i1[0] != i2[0] ? i1[0] - i2[0] : i1[1] - i2[1]
                   );
        
        List<int[]> ansList = new ArrayList<>();
        
        int startTime = intervals[0][0];
        int endTime = intervals[0][1];
        
        for (int[] interval : intervals)
        {
            // can merge interval
            if (interval[0] <= endTime)
            {
                endTime = Math.max(interval[1], endTime);
            }
            // they don't overlay
            else
            {
                ansList.add(new int[]{startTime, endTime});
                startTime = interval[0];
                endTime = interval[1];
            }
        }
        // add last interval
        ansList.add(new int[]{startTime, endTime});
            
        return ansList.toArray(new int[ansList.size()][]);
        
//         // below are equal to line 32
//         int[][] ans = new int[ansList.size()][2];
        
//         // change from arrayList<int[]> to int[][]
//         for (int i = 0; i < ansList.size(); i++)
//         {
//             ans[i] = ansList.get(i);
//         }
        
//         return ans;
    }
}


// Runtime: 11 ms, faster than 17.48% of Java online submissions for Merge Intervals.
// Memory Usage: 44.1 MB, less than 7.39% of Java online submissions for Merge Intervals.
// time complexity: O(n log n)
// space complexity: O(n)