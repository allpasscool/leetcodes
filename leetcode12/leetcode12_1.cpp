class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> numbers;
        char roman_num[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        
        do{
            int last_digit = num % 10;
            numbers.push_back(last_digit);
            num /= 10;
        }while(num != 0);
        
        string roman;
        
        for(int i = numbers.size() - 1; i >= 0; i--){
            
            //i = 3, 1000
            if(i == 3){
                for(int j = 0; j < numbers[i]; j++){
                    roman = roman + roman_num[0];
                }
            }
            else if(i == 2){
                if(numbers[i] == 9){
                    roman = roman + roman_num[2] + roman_num[0];
                }
                else if(numbers[i] == 4){
                    roman = roman + roman_num[2] + roman_num[1];
                }
                else if(numbers[i] >= 5){
                    roman = roman + roman_num[1];
                    for(int j = 5; j < numbers[i]; j++){
                        roman = roman + roman_num[2];
                    }
                }
                else{
                    for(int j = 0; j <numbers[i]; j++){
                        roman = roman + roman_num[2];
                    }
                }
            }
            else if(i == 1){
                if(numbers[i] == 9){
                    roman = roman + roman_num[4] + roman_num[2];
                }
                else if(numbers[i] == 4){
                    roman = roman + roman_num[4] + roman_num[3];
                }
                else if(numbers[i] >= 5){
                    roman = roman + roman_num[3];
                    for(int j = 5; j < numbers[i]; j++){
                        roman = roman + roman_num[4];
                    }
                }
                else{
                    for(int j = 0; j <numbers[i]; j++){
                        roman = roman + roman_num[4];
                    }
                }
            }
            else{
                if(numbers[i] == 9){
                    roman = roman + roman_num[6] + roman_num[4];
                }
                else if(numbers[i] == 4){
                    roman = roman + roman_num[6] + roman_num[5];
                }
                else if(numbers[i] >= 5){
                    roman = roman + roman_num[5];
                    for(int j = 5; j < numbers[i]; j++){
                        roman = roman + roman_num[6];
                    }
                }
                else{
                    for(int j = 0; j <numbers[i]; j++){
                        roman = roman + roman_num[6];
                    }
                }
            }
        }
        
        return roman;
    }
};
// Runtime: 16 ms, faster than 46.40% of C++ online submissions for Integer to Roman.
// Memory Usage: 9 MB, less than 37.34% of C++ online submissions for Integer to Roman.
// time complexity: O(log n)
// space complexity: O(log n)