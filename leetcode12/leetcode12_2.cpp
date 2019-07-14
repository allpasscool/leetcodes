class Solution {
public:
    string intToRoman(int num) {
        int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman_num[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int size_array = sizeof(numbers) / sizeof(int);
        
        string roman_numbers;
        
        for(int i = 0; i < size_array; i++){
            while(num >= numbers[i]){
                roman_numbers += roman_num[i];
                num -= numbers[i];
            }
        }
        
        return roman_numbers;
    }
};
// Runtime: 8 ms, faster than 82.37% of C++ online submissions for Integer to Roman.
// Memory Usage: 8.3 MB, less than 85.71% of C++ online submissions for Integer to Roman.
// time complexity: O(log n)
// space complexity: O(1)