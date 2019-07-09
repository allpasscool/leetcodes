class Solution {
public:
    int myAtoi(string str) {
        int start = 0;// start of digits
        bool pos = true;//positive
        
        //igonre whitespace characters
        for(int i = 0; i < str.size(); i++){
            if(str[i] != ' '){
                start = i;
                break;
            }
        }
        
        //sign
        if(str[start] == '+'){
            start++;
        }
        else if(str[start] == '-'){
            start++;
            pos = false;
        }
        
        //invalid
        if(str[start] > '9' || str[start] < '0'){
            return 0;
        }
        
        //digits
        //positive
        if(pos){
            int output = 0;
            
            for(int i = start; i < str.size(); i++){
                if(str[i] <= '9' && str[i] >= '0'){
                    if(output > INT_MAX / 10 || (output == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)){
                        output = INT_MAX;
                        break;
                    }
                    
                    output *= 10;
                    output += str[i] - '0';
                }
                else{
                    break;
                }
            }
            return output;
        }
        else{//negative
            int output = 0;
            
            for(int i = start; i < str.size(); i++){
                if(str[i] <= '9' && str[i] >= '0'){
                    if(output < INT_MIN / 10 || (output == INT_MIN / 10 && ('0' - str[i]) < INT_MIN % 10)){
                        output = INT_MIN;
                        break;
                    }
                    
                    output *= 10;
                    output -= str[i] - '0';
                }
                else{
                    break;
                }
            }
            return output;
        }
    }
};
// Runtime: 4 ms, faster than 90.07% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 8.4 MB, less than 64.27% of C++ online submissions for String to Integer (atoi).
//time complexity: O(n)
//space complexity: O(1)