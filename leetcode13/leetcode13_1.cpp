class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int roman[24];
        roman['I' - 'A'] = 1;
        roman['V' - 'A'] = 5;
        roman['X' - 'A'] = 10;
        roman['L' - 'A'] = 50;
        roman['C' - 'A'] = 100;
        roman['D' - 'A'] = 500;
        roman['M' - 'A'] = 1000;
        
        for(int i = 0; i < s.length(); i++){
            int current = roman[s[i] - 'A'];
            if((i+1) < s.length() && roman[s[i+1] - 'A'] > current){
                sum += roman[s[i+1] - 'A'] - current;
                i++;
            }
            else{
                sum += current;
            }
        }
        
        return sum;
    }
};
// Runtime: 4 ms, faster than 99.05% of C++ online submissions for Roman to Integer.
// Memory Usage: 8.2 MB, less than 93.87% of C++ online submissions for Roman to Integer.
// time complexity: O(n)
// space complexity: O(1)