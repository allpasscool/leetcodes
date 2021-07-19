class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> ansList = new ArrayList<>();
        int p1 = 0, p2 = 0; // pointer for A and B
        
        while (p1 < A.length && p2 < B.length)
        {
            // A is earlier than B
            if (A[p1][1] < B[p2][0])
            {
                p1++;
            }
            // B is earliser than A
            else if (B[p2][1] < A[p1][0])
            {
                p2++;
            }
            // overlay
            else if (B[p2][0] < A[p1][1] || A[p1][0] < B[p2][1])
            {
                // overlay is 
                // for example:
                // {3, 7}, {5, 8}
                // over lay is {max(3, 5), min(7, 8)}
                ansList.add(new int[]{Math.max(A[p1][0], B[p2][0]), Math.min(A[p1][1], B[p2][1])});
                
                // which ends first, should move to next interval
                if (A[p1][1] < B[p2][1]) 
                    p1++;
                else
                    p2++;
            }
        }
        
        return ansList.toArray(new int[ansList.size()][]);
    }
}

// Runtime: 2 ms, faster than 99.75% of Java online submissions for Interval List Intersections.
// Memory Usage: 40 MB, less than 45.37% of Java online submissions for Interval List Intersections.
// time complexity: O(n + m), which n is length of A and m is length of B
// space complexity: O(n + m)