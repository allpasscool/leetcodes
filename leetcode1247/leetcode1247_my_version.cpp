class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int ans = 0;
        
        int cx1 = 0, cy1 = 0;
        int cx2 = 0, cy2 = 0;
        
        for (auto c : s1) {
            if (c == 'x')
                ++cx1;
            if (c == 'y')
                ++cy1;
        }
        
        for (auto c : s2) {
            if (c == 'x')
                ++cx2;
            if (c == 'y')
                ++cy2;
        }
        
        if ((cx1 + cx2) % 2 != 0 || (cy1 + cy2) % 2 != 0)
            return -1;
        
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                ++xy;
            }
            else if (s1[i] == 'y' && s2[i] == 'x') {
                ++yx;
            }
        }
        
        // xx and yy, 1 swap
        // yy and xx, 1 swap
        // xy and yx, 2 swap
        
        return (xy + 1) / 2 + (yx + 1) / 2;
    }
};

// Runtime: 4 ms, faster than 60.00% of C++ online submissions for Minimum Swaps to Make Strings Equal.
// Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Minimum Swaps to Make Strings Equal.
// time complexity: O(n)
// space complexity: O(n)


// for example
// xxxyyy
// yyyxxx

// x1 = 3
// y1 = 3

// in this case, xx and yy is obvious, 1 swap.
// yy and xx is 1 swap.
// so we have the x1 / 2 + y1 / 2;
// then xy and yx
// because we first check
// if (x1 + y1) % 2 != 0:
// return -1
// which means s1 + s2 have enough x and y for s1 and s2
// therefore, if x1 is odd, then y1 must be odd.
// for xy and yx, we need 2 swap

// how about this case
// xyyx
// yxxy
// x1 = 2
// y1 = 2
// we can move change s1 and s2 like below
// xxyy
// yyxx
// as long as x[i] and y[i] is a pair, we can change i
// then we only need 2 swap

// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/discuss/419391/Detailed-Python-Solution
// def minimumSwap(self, s1, s2):
//         """
//         :type s1: str
//         :type s2: str
//         :rtype: int
//         """
        
//         x1 = 0
//         y1 = 0
      
//         for i in range(len(s1)):
//             if s1[i] != s2[i] and s1[i] == "x":
//                 x1 += 1

//             if s1[i] != s2[i] and s1[i] == "y":
//                 y1 += 1

//         if (x1 + y1) % 2 != 0:
//             return -1
            
        
//         return x1 / 2 + y1 / 2 + 2 * (x1 % 2)
// """ xx, yy needs one swap, and xy yx needs two swaps, so find the pair of x and the number of redundant x"""