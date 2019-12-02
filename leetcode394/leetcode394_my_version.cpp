class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans;
        int i = 0;
        int n = s.length();
        
        while (i < n) {
            string substring;
            int num;
            // meet ]
            if (s[i] == ']') {
                // get substring
                while (st.top() != "[") {
                    substring = st.top() + substring;
                    st.pop();
                }
                st.pop();
                
                // get num
                string num_string;
                while (!st.empty()) {
                    if (st.top().length() > 1) {
                        break;
                    }
                    else if (st.top()[0] < '0' || st.top()[0] > '9') {
                        break;
                    }
                    
                    num_string = st.top() + num_string;
                    st.pop();
                }
                
                num = stoi(num_string);
                
                string tmp;
                for (int j = 0; j < num; ++j) {
                    tmp += substring;
                }
                
                st.push(tmp);
            }
            else {
                st.push(s.substr(i, 1));
            }
            
            ++i;
        }
        
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};


// Runtime: 4 ms, faster than 55.22% of C++ online submissions for Decode String.
// Memory Usage: 8.8 MB, less than 94.12% of C++ online submissions for Decode String.
// time complexity: O(n)
// space complexity: O(n)