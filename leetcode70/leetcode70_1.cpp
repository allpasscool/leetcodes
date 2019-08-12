class Solution {
public:
    int climbStairs(int i, int n) {
        if(i > n) {
            return 0;
        } else if (i == n) {
            return 1;
        }
        
        return climbStairs(i + 1, n) + climbStairs(i + 2, n);
    }
    
    int climbStairs(int n) {
        return climbStairs(0, n);  
    }
};
// time limit exceed
// time complexity: O(2^n)
// space complexity: O(n) The depth of the recursion tree can go upto nn. 