class Solution {
    List<Integer> arrL;
    
    public Solution(int[] w) {
        arrL = new ArrayList<>();
        int accumulatedSum = 0;
        arrL.add(0);
        for (int i = 0; i < w.length; i++)
        {
            accumulatedSum += w[i];
            arrL.add(accumulatedSum);
        }
    }
    
    
    // w = [1, 2, 3, 4, 5, 6]
    // arrL = {0, 1, 3, 6, 10, 15, 21}
    public int pickIndex() {
        // List<Integer> tmp = new ArrayList<>(arrL);
        
        Random r = new Random();
        int rand = r.nextInt(arrL.get(arrL.size() - 1));
        
        // binary search
        int left = 0, right = arrL.size();
        int ans = 0;
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            
            if (arrL.get(mid) == rand)
            {
                return mid;
            }
            else if (arrL.get(mid) < rand)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        
        return ans;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

// Runtime: 27 ms, faster than 31.43% of Java online submissions for Random Pick with Weight.
// Memory Usage: 43.5 MB, less than 92.71% of Java online submissions for Random Pick with Weight.
// time complexity: O(log n)
// space complexity: O(n)