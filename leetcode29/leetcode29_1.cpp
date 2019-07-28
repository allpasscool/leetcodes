class Solution {
public:
    int opposite(int x){
        return ~x + 1;//get complement number
    }
    
    int divide(int dividend, int divisor) {
        int ans = 0, sign = 1;//we since INT_MIN has one more value than INT_MAX, we use negative to count the number
        
        //if dividend is positive, we change it to its complement number, which will be negatvie number, and change the sign
        if(dividend > 0){
            sign = opposite(sign);
            dividend = opposite(dividend);
        }
        
        //same as we do to dividend
        if(divisor > 0){
            sign = opposite(sign);
            divisor = opposite(divisor);
        }
        
        int origin_dividend = dividend, origin_divisor = divisor;
        
        //if dividend > than divisor, for example -3 > -4, than return 0
        if(dividend > divisor){
            return 0;
        }
        
        //first, count one
        dividend -= divisor;
        ans--;
        while(divisor >= dividend){
            ans += ans;
            dividend -= divisor;
            divisor += divisor;
        }
        
        int a = ans + opposite(divide(origin_dividend - divisor, origin_divisor));
        if(a == INT_MIN){
            if(sign > 0){
                return INT_MAX;
            } else{
                return INT_MIN;
            }
        } else{
            if(sign > 0){
                return opposite(a);
            } else{
                return a;
            }
        }
    }
};
// Runtime: 4 ms, faster than 81.21% of C++ online submissions for Divide Two Integers.
// Memory Usage: 8.2 MB, less than 59.53% of C++ online submissions for Divide Two Integers.
// time complexity: O(log n)
// space complexity: O(1)