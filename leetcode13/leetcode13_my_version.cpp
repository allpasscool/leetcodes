class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        std::unordered_map<char, int> roman_to_numbers;
        roman_to_numbers['I'] = 1;
        roman_to_numbers['V'] = 5;
        roman_to_numbers['X'] = 10;
        roman_to_numbers['L'] = 50;
        roman_to_numbers['C'] = 100;
        roman_to_numbers['D'] = 500;
        roman_to_numbers['M'] = 1000;
        
        for(int i = 0; i < s.length(); i++){
            if((i+1) < s.length() && roman_to_numbers[s[i+1]] > roman_to_numbers[s[i]]){
                sum += roman_to_numbers[s[i+1]] - roman_to_numbers[s[i]];
                i++;
            }
            else{
                sum += roman_to_numbers[s[i]];
            }
        }
        
        return sum;
    }
};
// Runtime: 12 ms, faster than 84.50% of C++ online submissions for Roman to Integer.
// Memory Usage: 11.3 MB, less than 14.02% of C++ online submissions for Roman to Integer.
// time complexity: O(n)
// space complexity: O(1)