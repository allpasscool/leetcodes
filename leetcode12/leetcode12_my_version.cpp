class Solution {
public:
    string intToRoman(int num) {
        std::vector<int> numbers;
        
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
                    roman = roman + "M";
                }
            }
            else if(i == 2){
                if(numbers[i] == 9){
                    roman = roman + "CM";
                }
                else if(numbers[i] == 4){
                    roman = roman + "CD";
                }
                else if(numbers[i] >= 5){
                    roman = roman + "D";
                    for(int j = 5; j < numbers[i]; j++){
                        roman = roman + "C";
                    }
                }
                else{
                    for(int j = 0; j <numbers[i]; j++){
                        roman = roman + "C";
                    }
                }
            }
            else if(i == 1){
                if(numbers[i] == 9){
                    roman = roman + "XC";
                }
                else if(numbers[i] == 4){
                    roman = roman + "XL";
                }
                else if(numbers[i] >= 5){
                    roman = roman + "L";
                    for(int j = 5; j < numbers[i]; j++){
                        roman = roman + "X";
                    }
                }
                else{
                    for(int j = 0; j <numbers[i]; j++){
                        roman = roman + "X";
                    }
                }
            }
            else{
                if(numbers[i] == 9){
                    roman = roman + "IX";
                }
                else if(numbers[i] == 4){
                    roman = roman + "IV";
                }
                else if(numbers[i] >= 5){
                    roman = roman + "V";
                    for(int j = 5; j < numbers[i]; j++){
                        roman = roman + "I";
                    }
                }
                else{
                    for(int j = 0; j <numbers[i]; j++){
                        roman = roman + "I";
                    }
                }
            }
        }
        
        return roman;
    }
};
// Runtime: 8 ms, faster than 82.37% of C++ online submissions for Integer to Roman.
// Memory Usage: 9 MB, less than 37.70% of C++ online submissions for Integer to Roman.
//time complexity: O(log n)
//space compexity: O(log n)