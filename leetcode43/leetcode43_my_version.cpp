class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1.length() < num2.length()) {
            return multiply(num2, num1);
        }
        
        //num1.length() >= nu2.length()
        string output;
        
        //times num2
        for (int i = num2.length() - 1; i >= 0; i--) {
            int times = num2[i] - '0';
            int carry = 0;
            
            string tmp = "";
            
            //add 0 in the back, showing *1, *10, *100 and so on
            for (int j = i; j < num2.length() - 1; j++) {
                tmp += "0";
            }
            
            //each num1 digits times num2[i]
            for(int j = num1.length() - 1; j >= 0; j--) {
                int n = num1[j] - '0';
                
                //times 0, special case
                if (times == 0) {
                    tmp = "";
                    break;
                }
                
                n *= times;
                n += carry;
                carry = n / 10;
                n = n % 10;
                tmp.insert(0, 1, (char)(n + '0'));
            }
            
            if (carry != 0) {
                tmp = (char)(carry + '0') + tmp;
            }

            //output + tmp
            if (output.empty()) {
                output = tmp;
            } else if (!tmp.empty()){
                carry = 0;
                
                for (int j = 1; j <= output.length(); j++) {
                    int n1 = tmp[tmp.length() - j] - '0', n2 = output[output.length() - j] - '0';
                    
                    n1 += n2;
                    n1 += carry;
                    carry = n1 / 10;
                    n1 = n1 % 10;
                    tmp[tmp.length() - j] = (char)(n1 + '0');
                }
                
                if (carry != 0) {
                    if (output.length() < tmp.length()) {
                        int j = 1;
                        for (; (tmp.length() - output.length()) >= j && carry != 0; j++){
                            int n = tmp[tmp.length() - output.length() - j] - '0';

                            n += carry;
                            carry = n / 10;
                            n = n % 10;

                            tmp[tmp.length() - output.length() - j] = (char)(n + '0');
                        }
                        
                        if (tmp.length() - output.length() < j && carry != 0) {
                            tmp = (char)(carry + '0') + tmp;
                        }
                    } else {
                        tmp = (char)(carry + '0') + tmp;
                    }
                }
                output = tmp;
            }
        }
        
        if (output.empty()) {
            return "0";
        }
        
        return output;
    }
};
// Runtime: 24 ms, faster than 21.13% of C++ online submissions for Multiply Strings.
// Memory Usage: 10.7 MB, less than 12.82% of C++ online submissions for Multiply Strings.
// time complexity: O(m * (n+m)) , n is num1, m is num2
// space complexity: O(n + m)