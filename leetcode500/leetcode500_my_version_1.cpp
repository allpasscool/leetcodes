class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> output;
        
        for (auto& s: words) {
            bool same_row = true;
            
            for (int i = 0; i < s.length() - 1; i++) {
                if (getRow(s[i]) != getRow(s[i + 1])) {
                    same_row = false;
                    break;
                }
            }
            
            if (same_row)
                output.push_back(s);
        }
        
        
        return output;
    }
    
private:
    int getRow(char c) {
        
        switch (c){
            case 'Q':
            case 'q':
            case 'W':
            case 'w':
            case 'E':
            case 'e':
            case 'R':
            case 'r':
            case 'T':
            case 't':
            case 'Y':
            case 'y':
            case 'U':
            case 'u':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'P':
            case 'p':
                return 0;
            case 'A':
            case 'a':
            case 'S':
            case 's':
            case 'D':
            case 'd':
            case 'F':
            case 'f':
            case 'G':
            case 'g':
            case 'H':
            case 'h':
            case 'J':
            case 'j':
            case 'K':
            case 'k':
            case 'L':
            case 'l':
                return 1;
            case 'Z':
            case 'z':
            case 'X':
            case 'x':
            case 'C':
            case 'c':
            case 'V':
            case 'v':
            case 'B':
            case 'b':
            case 'N':
            case 'n':
            case 'M':
            case 'm':
                return 2;
        }
        
        return -1;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
// Memory Usage: 8.5 MB, less than 85.71% of C++ online submissions for Keyboard Row.
// time complexity: O(n)
// space complexity: O(1)