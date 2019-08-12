class Solution {
public:
    int climbStairs(int i, int n, vector<int>& output) {
        if(i > n) {
            return 0;
        } else if (i == n) {
            return 1;
        } else if (output[i] > 0) {
            return output[i];
        }
        
        output[i] = climbStairs(i + 1, n, output) + climbStairs(i + 2, n, output);
        
        return output[i];
    }
    
    int climbStairs(int n) {
        vector<int> output(n + 1, 0);
        return climbStairs(0, n, output);  
    }
};
// Runtime: 4 ms, faster than 53.64% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.6 MB, less than 20.59% of C++ online submissions for Climbing Stairs.
// time complexity: O(n) Size of recursion tree can go upto nn.
// space complexity: O(n) The depth of recursion tree can go upto nn. 