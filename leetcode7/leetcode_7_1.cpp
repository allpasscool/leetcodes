class Solution {
public:
    int reverse(int x) {
        if(x == 0){
            return x;
        }
        else if( x > 0){//positive
            int output = 0;
            
            do{
                if(output > (INT_MAX / 10)){
                    return 0;
                }
                else if(output == INT_MAX / 10 && x % 10 > INT_MAX % 10){
                    return 0;
                }
                
                output *= 10;
                output += x % 10;
                x /= 10;
            }while(x != 0);
            
            return output;
        }
        else{//negative
            int output = 0;
            
            do{
                if(output < (INT_MIN / 10)){
                    return 0;
                }
                else if(output == INT_MIN / 10 && x % 10 < INT_MIN % 10){
                    return 0;
                }
                
                output *= 10;
                output += x % 10;
                x /= 10;
                
            }while(x != 0);
            
            return output;
        }
        
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
// Memory Usage: 8.1 MB, less than 66.13% of C++ online submissions for Reverse Integer.
// Time Complexity: O(log(x)). There are roughly log (x) digits in x.
// Space Complexity: O(1).