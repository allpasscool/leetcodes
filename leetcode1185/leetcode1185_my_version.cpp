class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days_count = 0;
        
        for (int i = 1971; i < year; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0 && i % 3200 != 0)) {
                days_count += 366;
            }
            else {
                days_count += 365;
            }
        }
        
        for (int i = 1; i < month; i++) {
            int d = 0;
            
            switch(i) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    d = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    d = 30;
                    break;
                case 2:
                    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0)) {
                        d = 29;
                    }
                    else {
                        d = 28;
                    }
                    break;
            }
            
            days_count += d;
        }
        
//         cout << days_count << endl;
        
        days_count += day;
        
        days_count += 4;
        
        // cout << days_count << endl;
        
        // if (year > 1971) {
        //     days_count += 1;
        // }
        
        days_count %= 7;
        
        string output = "";
        
        switch(days_count) {
            case 1:
                output = "Monday";
                break;
            case 2:
                output = "Tuesday";
                break;
            case 3:
                output = "Wednesday";
                break;
            case 4:
                output = "Thursday";
                break;
            case 5:
                output = "Friday";
                break;
            case 6:
                output = "Saturday";
                break;
            case 0:
                output = "Sunday";
                break;
        }
        
        return output;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Day of the Week.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Day of the Week.
// time complexity: O(m + (y - 1971))
// space complexity: O(1)