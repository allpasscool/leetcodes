class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int cur = 0;
        queue<int> q;
        
        // read string
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            // number
            if (isdigit(c)) {
                cur = cur * 10 + (int)(c - '0');
            }
            // operators
            else {
                // +
                if (c == '+') {
                    q.push(cur);
                    q.push(c);
                    cur = 0;
                }
                // -
                else if (c == '-') {
                    q.push(cur);
                    q.push(c);
                    cur = 0;
                }
                // *
                else if (c == '*') {
                    int next = 0;
                    
                    ++i;
                    while (isdigit(s[i])) {
                        next = next * 10 + (int)(s[i] - '0');
                        ++i;
                    }
                    i--;
                    
                    cur *= next;
                }
                // /
                else if (c == '/') {
                    int next = 0;
                    
                    ++i;
                    // escape spaces
                    while (s[i] == ' ') {
                        ++i;
                    }
                    // get next int
                    while (isdigit(s[i])) {
                        next = next * 10 + (int)(s[i] - '0');
                        ++i;
                    }
                    i--;
                    
                    cur /= next;
                }
            }
        }
        
        // push last number into queue
        q.push(cur);
        
        // read queue
        sum = q.front();
        q.pop();
        while (!q.empty()) {
            if (q.front() == '+') {
                q.pop();
                sum += q.front();
                q.pop();
            }
            else if (q.front() == '-') {
                q.pop();
                sum -= q.front();
                q.pop();
            }
        }
        
        return sum;
    }
};

// Runtime: 24 ms, faster than 78.72% of C++ online submissions for Basic Calculator II.
// Memory Usage: 9.3 MB, less than 22.77% of C++ online submissions for Basic Calculator II.
// time complexity: O(n)
// space complexity: O(n)