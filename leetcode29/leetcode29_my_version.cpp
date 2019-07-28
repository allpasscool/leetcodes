class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 0){
            return 0;
        } else if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        } else if(dividend < 0 && divisor < dividend){
            return 0;
        } else if(dividend > 0 && divisor > dividend){
            return 0;
        }
        
        int output = 0;
        bool is_negative = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            is_negative = true;
        }
        
        int dividend_last = dividend, divisor_now = divisor, times = 1, power = 1;
        
        if(is_negative){//only dividend or divisor is negative
            if(dividend > 0){
                dividend_last += divisor_now;
                if(dividend_last >= 0){
                    output -= times;
                }
                
                while(dividend_last > 0 && dividend_last + divisor >= 0){
                    if(dividend_last + divisor_now >= 0 && output >= INT_MIN + times){
                        dividend_last += divisor_now;
                        output -= times;
                        
                        if(power < 14){
                            power++;
                            times += times;
                            divisor_now += divisor_now;
                        }
                    } else{
                        int reduce_times = 1, reduce_divisor = divisor;
                        // while(dividend_last + divisor_now < 0 && divisor_now < reduce_divisor){
                        //     times -= reduce_times;
                        //     divisor_now -= reduce_divisor;
                        //     reduce_times += reduce_times;
                        //     reduce_divisor += reduce_divisor;
                        // }
                        times--;
                        divisor_now -= divisor;
                    }
                }
            }else{
                dividend_last += divisor_now;
                if(dividend_last <= 0){
                    output -= times;
                }
                
                while(dividend_last < 0 && dividend_last + divisor <= 0){
                    if(dividend_last + divisor_now <= 0 && output >= INT_MIN + times){
                        dividend_last += divisor_now;
                        output -= times;
                        
                        if(power < 14){
                            power++;
                            times += times;
                            divisor_now += divisor_now;
                        }
                    } else{
                        times--;
                        divisor_now -= divisor;
                    }
                }
            }
        }else{//both dividend and divisor are positive or negative
            if(dividend >= 0){
                dividend_last -= divisor_now;
                if(dividend_last >= 0){
                    output += times;
                }
                
                while(dividend_last > 0 && dividend_last - divisor >= 0){
                    if(dividend_last - divisor_now >= 0 && INT_MAX - output >= times){
                        dividend_last -= divisor_now;
                        output += times;
                        
                        if(power < 14){
                            power++;
                            times += times;
                            divisor_now += divisor_now;
                        }
                    } else{
                        times--;
                        divisor_now -= divisor;
                    }
                    // output++;
                    // dividend -= divisor;
                }
            }else{
                dividend_last -= divisor_now;
                if(dividend_last <= 0){
                    output += times;
                }
                
                
                while(dividend_last < 0 && dividend_last - divisor <= 0){
                    if(dividend_last - divisor_now <= 0 && INT_MIN + times <= output){
                        dividend_last -= divisor_now;
                        output += times;
                        
                        if(power < 14){
                            power++;
                            times += times;
                            divisor_now += divisor_now;
                        }
                    } else{
                        times--;
                        divisor_now -= divisor;
                    }
                }
            }
        }
        
        return output;
    }
};
// Runtime: 4 ms, faster than 81.42% of C++ online submissions for Divide Two Integers.
// Memory Usage: 8.1 MB, less than 84.73% of C++ online submissions for Divide Two Integers.
// time complexity: O(n)
// space complexity: O(1)