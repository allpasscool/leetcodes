class Solution {
public:
    vector<vector<int>> pow(vector<vector<int>>& a, int n) {
        vector<vector<int>> ret = {vector<int> {1, 0}, vector<int> {0, 1}};//I, matrix * I = matrix
        
        /*
        n   35  17  8   4   2       1
        ret 1   1+2 3   3   3       3+32
        a   1+1 2+2 4+4 8+8 16+16   
        */
        while (n > 0) {
            if (n % 2 == 1) {
                ret = multiply(ret, a);
            }
            
             //to avoid useless calculation multiply(a, a), might be too big
            if (n == 1) {
                break;
            }
            n /= 2;
            a = multiply(a, a);
        }
        
        return ret;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> c = {vector<int> (2, 0), vector<int> (2, 0)};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        
        return c;
    }
    
    int climbStairs(int n) {
        vector<vector<int>> q = {vector<int> {1, 1}, vector<int> {1, 0}};
        vector<vector<int>> res = pow(q, n);
        
        return res[0][0];
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
// Memory Usage: 8.3 MB, less than 86.76% of C++ online submissions for Climbing Stairs.
// time complexity: O(logn)
// space complexity: O(1)