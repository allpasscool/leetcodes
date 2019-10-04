class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        
        string output = "";
        vector<string> helper = {"", "Thousand", "Million", "Billion"};
        int count = 0; // times of thounsand
        
        while (num != 0) {
            
            int tmp = num % 1000;
            if (tmp == 0) {
                ++count;
                num /= 1000;
                continue;
            }
            
            if (output.length() != 0) {
                output = " " + output;
                // cout << "enter" << endl;
            }
            
            if (tmp == 10) {
                if (count == 0) {
                    output = numToEnglish(tmp);
                }
                else {
                    output = numToEnglish(tmp) + " " + helper[count] + output;
                }
            }
            else if (tmp % 100 == 0 && tmp / 100 != 0) {
                if (count == 0) {  
                    output = numToEnglish(tmp / 100) + " Hundred";
                }
                else {
                    output = numToEnglish(tmp / 100) + " Hundred " + helper[count] + output;
                }
            }
            else {
                // 11 - 19 || 10, 20, 30, 40
                if (tmp % 100 < 20 && tmp % 100 > 10) {
                    if (count == 0) {
                        output = numToEnglish(tmp % 100);
                    }
                    else {
                        output = numToEnglish(tmp % 100) + " " + helper[count] + output;
                    }
                }
                // 10, 20, 30, 40 ...
                else if (tmp % 10 == 0) {
                    if (count == 0) {
                        output = numToEnglish(tmp % 100);
                    }
                    else {
                        output = numToEnglish(tmp % 100) + " " + helper[count] + output;
                    }
                }
                // 03, 23 ...
                else {
                    if (count == 0) {
                        output = numToEnglish(tmp % 10);
                    }
                    else {
                        output = numToEnglish(tmp % 10) + " " + helper[count] + output;
                    }
                    if (tmp / 10 % 10 * 10 != 0)
                        output = numToEnglish(tmp / 10 % 10 * 10) + " " + output;
                }
                // hundreds 1XX
                if (tmp / 100 != 0)
                    output = numToEnglish(tmp / 100) + " Hundred " + output;
            }
            
            ++count;
            num /= 1000;
        }
        
        return output;
    }
    
private: 
    string numToEnglish(int x) {
        switch(x) {
            case 0:
                return "";
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
            case 20:
                return "Twenty";
            case 30:
                return "Thirty";
            case 40:
                return "Forty";
            case 50:
                return "Fifty";
            case 60:
                return "Sixty";
            case 70:
                return "Seventy";
            case 80:
                return "Eighty";
            case 90:
                return "Ninety";
        }
        
        cout << x << " Error" << endl;
        return "Error";
    }
};

// Runtime: 4 ms, faster than 80.07% of C++ online submissions for Integer to English Words.
// Memory Usage: 8.9 MB, less than 46.15% of C++ online submissions for Integer to English Words.
// time complexity: O(num)
// space complexity: O(1)