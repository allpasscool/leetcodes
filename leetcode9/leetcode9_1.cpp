class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0 ){
            return false;
        }
        else if(x == 0){
            return true;
        }
        else if(x % 10 == 0){
            return false;
        }
        else{
            int reverse_x = 0;
            
            do{
                reverse_x = reverse_x * 10 + x % 10;
                x /= 10;
            }while(x > reverse_x);
            
            return x == reverse_x || x == (reverse_x / 10);
        }
    }
};

// Runtime: 8 ms, faster than 94.09% of C++ online submissions for Palindrome Number.
// Memory Usage: 8 MB, less than 70.50% of C++ online submissions for Palindrome Number.
//time complexity: O(log x)
//space complexity: O(1)