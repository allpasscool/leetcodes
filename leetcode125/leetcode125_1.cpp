class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, back = s.length() - 1;
        
        while (front < back) {
            while (!isalnum(s[front]) && front < back) {
                ++front;
            }
            while (!isalnum(s[back]) && front < back) {
                back--;
            }
            
            if (tolower(s[front]) != tolower(s[back])) {
                return false;
            }
            ++front;
            back--;
        }
        
        return true;
    }
};

// Runtime: 4 ms, faster than 99.42% of C++ online submissions for Valid Palindrome.
// Memory Usage: 9.6 MB, less than 26.53% of C++ online submissions for Valid Palindrome.
// time complexity: O(n)
// space complexity: O(1)
    
//     bool isPalindrome(string s) {
//         for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
//             while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
//             while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
//             if (toupper(s[i]) != toupper(s[j])) {
//                 cout << s[i] << " " << s[j];
//                 return false; // Exit and return error if not match
//             }
//         }

//         return true;
//     }
