class Solution {
public:
    string addBinary(string a, string b) {
        if (b.length() > a.length()) {
            swap(a, b);
        }
        
        //a.length() >= b.length()
        for (int i = 1; i <= b.length(); i++) {
            a[a.length() - i] += b[b.length() - i] - '0';
        }
        
        for (int i = a.length() - 1; i > 0; i--) {
            if (a[i] >= '2') {
                a[i - 1]++;
                a[i] -= 2;
            }
        }
        
        if (a[0] >= '2') {
            a[0] -= 2;
            a = "1" + a;
        }
        
        return a;
    }
};

// Runtime: 4 ms, faster than 81.10% of C++ online submissions for Add Binary.
// Memory Usage: 8.4 MB, less than 98.18% of C++ online submissions for Add Binary.
// time complexity: O(n + m), n is length of a, m is length of b
// space complexity: O(1)