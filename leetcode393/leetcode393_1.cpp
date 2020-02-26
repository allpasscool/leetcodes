class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        
        for (auto c : data) {
            if (count == 0) {
                if (c >> 5 == 0b110)
                    count = 1;
                else if ((c >> 4) == 0b1110)
                    count = 2;
                else if ((c >> 3) == 0b11110)
                    count = 3;
                else if (c >> 7)
                    return false;
            }
            else {
                if ((c >> 6) != 0b10)
                    return false;
                count--;
            }
        }
        
        return count == 0;
    }
};


// Runtime: 12 ms, faster than 95.36% of C++ online submissions for UTF-8 Validation.
// Memory Usage: 9.5 MB, less than 87.50% of C++ online submissions for UTF-8 Validation.
// time complexity: O(n)
// space complexity: O(1)

// https://leetcode.com/problems/utf-8-validation/discuss/87462/Concise-C%2B%2B-implementation
// class Solution {
// public:
//     bool validUtf8(vector<int>& data) {
//         int count = 0;
//         for (auto c : data) {
//             if (count == 0) {
//                 if ((c >> 5) == 0b110) count = 1;
//                 else if ((c >> 4) == 0b1110) count = 2;
//                 else if ((c >> 3) == 0b11110) count = 3;
//                 else if ((c >> 7)) return false;
//             } else {
//                 if ((c >> 6) != 0b10) return false;
//                 count--;
//             }
//         }
//         return count == 0;
//     }
// };

