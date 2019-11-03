class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        
        for (int i = 0; i < nums.size(); ++i) {
            g = __gcd(nums[i], g);
            if (g == 1)
                return true;
        }
        
        return false;
    }
};

// Runtime: 84 ms, faster than 66.67% of C++ online submissions for Check If It Is a Good Array.
// Memory Usage: 14.5 MB, less than 100.00% of C++ online submissions for Check If It Is a Good Array.
// time complexity: O(n)
// space complexity: O(1)
// https://leetcode.com/problems/check-if-it-is-a-good-array/discuss/419324/Bezout's-Identity

// Read (https://brilliant.org/wiki/bezouts-identity/, https://en.wikipedia.org/wiki/Bézout's_identity)
// The basic idea is that for integers a and b, if gcd(a,b) = d, then there exist integers x and y, s.t a * x + b * y = d;
// This can be generalized for (n >= 2) . e.g. if gcd(a,b,c) = d, then there exist integers x, y, and z, s.t, a* x + b*y + c * z = d.
// Now this problem is just asking if gcd(x1, ......, xn) = 1

// class Solution {
// public:
//     bool isGoodArray(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0] == 1;
//         
//         int a = nums[0];
//         
//         for (int i = 1; i < nums.size(); i++) {
//             if (__gcd(a, nums[i]) == 1) return true;
//             a = __gcd(a, nums[i]);
//         }
//         
//         return false;
//     }
// };