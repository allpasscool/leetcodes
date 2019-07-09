class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ){
            return false;
        }
        else if(x == 0){
            return true;
        }
        else{
            std::vector<int> num;
            
            while(x != 0){
                num.push_back(x % 10);
                x /= 10;
            }
            
            int start = 0, end = num.size() - 1;
            
            while(start < end){
                if(num[start] != num[end]){
                    return false;
                }
                
                start++;
                end--;
            }
            
            return true;
        }
    }
};

// Runtime: 24 ms, faster than 49.24% of C++ online submissions for Palindrome Number.
// Memory Usage: 11.5 MB, less than 12.94% of C++ online submissions for Palindrome Number.
//time complexity: O(log x)
//space complexity: O(log x)