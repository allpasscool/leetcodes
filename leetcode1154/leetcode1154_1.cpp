class Solution {
public:
    int dayOfYear(string date) {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        bool is_lunar = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int output = 0;
        
        for(int i = 1; i < month; i++) {
            switch (i){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    output += 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    output += 30;
                    break;
                case 2:
                    if (is_lunar) {
                        output += 29;
                    } else {
                        output += 28;
                    }
            }
        }
        output += day;
        
        return output;
    }
};
// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Day of the Year.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Day of the Year.
// time complexity: O(month)
// space complexity: O(1)