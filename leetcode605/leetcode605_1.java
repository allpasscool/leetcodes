class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0
               && (i == 0 || flowerbed[i - 1] == 0)
               && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        
        return n <= 0;
    }
}


// Runtime: 1 ms, faster than 86.21% of Java online submissions for Can Place Flowers.
// Memory Usage: 40.7 MB, less than 26.25% of Java online submissions for Can Place Flowers.
// time complexity: O(n)
// space complexity: O(1)