class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string output = "1";
        n--;
        
        for(int i = 0; i < n; i++) {
            string tmp = "";
            int num = 1, digit = output[0] - '0';
            
            for (int j = 1; j < output.length(); j++) {
                if (output[j] - '0' != digit) {
                    tmp += (char) (num + '0');
                    tmp += (char) (digit + '0');
                    num = 1;
                    digit = (int) (output[j] - '0');
                } else {
                    num++;
                }
            }
            
            tmp += (char) (num + '0');
            tmp += (char) (digit + '0');;
            output = tmp;
        }
        
        return output;
    }
};

// Runtime: 4 ms, faster than 79.76% of C++ online submissions for Count and Say.
// Memory Usage: 8.7 MB, less than 88.66% of C++ online submissions for Count and Say.
// time comlexity: O(n * m), n is nth, m is the longest length of output
// space complexity: O(m)