class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        
        for (int i = 0; i < (1 << n); ++i) {
            ans.push_back(start ^ (i ^ (i >> 1)));
        }
        
        // generate gray code from 0 to 2^n-1
        // for (int i = 0; i < pow(2, n); ++i) {
        //     cout << (i ^ (i >> 1)) << endl;
        // }
                          
        return ans;
    }
};


// Runtime: 176 ms, faster than 80.07% of C++ online submissions for Circular Permutation in Binary Representation.
// Memory Usage: 15.5 MB, less than 100.00% of C++ online submissions for Circular Permutation in Binary Representation.
// time complexity: O(2^n)
// space complexity: O(1)
// https://leetcode.com/problems/circular-permutation-in-binary-representation/discuss/414203/JavaC%2B%2BPython-4-line-Gray-Code

// class Solution {
// public:
//     vector<int> circularPermutation(int n, int start) {
//         vector<int> res;
//         for (int i = 0; i < 1 << n; ++i)
//             res.push_back(start ^ i ^ i >> 1);
//         return res;
//     }
// };