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
                output *= 10;
                if(output > INT_MAX - x % 10){
                    return 0;
                }
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
                output *= 10;
                if(output < INT_MIN - x % 10){
                    return 0;
                }
                output += x % 10;
                x /= 10;
            }while(x != 0);
            
            return output;
        }
        
    }
};
// Runtime: 4 ms, faster than 79.66% of C++ online submissions for Reverse Integer.
// Memory Usage: 8.2 MB, less than 48.21% of C++ online submissions for Reverse Integer.
//time complexity: O(n), n is lenght of interger x
//space complexity: O(1)