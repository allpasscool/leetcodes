class Solution {
    Random random;
    int[] wSums;
    
    public Solution(int[] w) {
        this.random = new Random();
        for(int i = 1; i < w.length; i++)
            w[i] += w[i - 1];
        this.wSums = w;
    }
    
    public int pickIndex() {
        int nextInt = random.nextInt(wSums[wSums.length - 1]);
        int i = Arrays.binarySearch(wSums, nextInt);
        
        return Math.abs(i + 1);
    }
}

// https://leetcode.com/problems/random-pick-with-weight/discuss/154044/Java-accumulated-freq-sum-and-binary-search
// Runtime: 30 ms, faster than 27.45% of Java online submissions for Random Pick with Weight.
// Memory Usage: 52.8 MB, less than 5.01% of Java online submissions for Random Pick with Weight.
// time complexity: O(log n)
// space complexity: O(n)