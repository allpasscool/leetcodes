class Solution {
public:
    int compress(vector<char>& chars) {
        // string compression = "";
        int count = 1;
        int write_pos = 0;
        
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == chars[i - 1])
                ++count;
            else {
                // compression += chars[i - 1];
                chars[write_pos] = chars[i - 1];
                ++write_pos;
                
                if (count != 1) {
                    string tmp = to_string(count);
                    for (int j = 0; j < tmp.length(); ++j) {
                        chars[write_pos] = tmp[j];
                        ++write_pos;
                    }
                    
                }
                count = 1;
            }
        }
        
        if (chars.size() > 0) {
            // compression += chars[chars.size() - 1];
            chars[write_pos] = chars[chars.size() - 1];
            ++write_pos;
        }
        if (count != 1) {
            // compression += to_string(count);
            string tmp = to_string(count);
            for (int j = 0; j < tmp.length(); ++j) {
                chars[write_pos] = tmp[j];
                ++write_pos;
            }
        }
        
        // for (int i = 0; i < compression.length(); ++i)
        //     chars[i] = compression[i];
        
        // return compression.length();
        return write_pos;
    }
};

// Runtime: 8 ms, faster than 85.50% of C++ online submissions for String Compression.
// Memory Usage: 9.2 MB, less than 83.33% of C++ online submissions for String Compression.
// time complexity: O(n)
// space complexity: O(1)