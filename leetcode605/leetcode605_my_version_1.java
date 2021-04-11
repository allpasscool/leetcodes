class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int f_len = flowerbed.length;
        
        // only 1 space
        if (f_len == 1) {
            if (n + flowerbed[0] <= 1)
                return true;
            else 
                return false;
        }
        
        // i == 0
        if (flowerbed[0] == 0
           && flowerbed[1] != 1) {
            flowerbed[0] = 1;
            n--;
        }
        
        // i = n-1
        if (flowerbed[f_len-1] == 0
           && flowerbed[f_len-2] != 1) {
            flowerbed[f_len-1] = 1;
            n--;
        }
        
        for (int i = 1; i < f_len - 1; i++) {
            if (flowerbed[i] == 0
              && flowerbed[i-1] != 1
              && flowerbed[i+1] != 1) {
                flowerbed[i] = 1;
                n--;
            }
                
        }
        
        return n <= 0;
    }
}


// Runtime: 1 ms, faster than 86.21% of Java online submissions for Can Place Flowers.
// Memory Usage: 40.6 MB, less than 36.46% of Java online submissions for Can Place Flowers.
// time complexity: O(n)
// space complexity: O(1)