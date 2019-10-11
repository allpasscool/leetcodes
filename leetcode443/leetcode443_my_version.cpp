class Solution {
public:
    int compress(vector<char>& chars) {
        string compression = "";
        int count = 1;
        
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == chars[i - 1])
                ++count;
            else {
                compression += chars[i - 1];
                if (count != 1)
                    compression += to_string(count);
                count = 1;
            }
        }
        
        if (chars.size() > 0)
            compression += chars[chars.size() - 1];
        if (count != 1)
            compression += to_string(count);
        
        for (int i = 0; i < compression.length(); ++i)
            chars[i] = compression[i];
        
        return compression.length();
    }
};

// Runtime: 8 ms, faster than 85.50% of C++ online submissions for String Compression.
// Memory Usage: 9.2 MB, less than 83.33% of C++ online submissions for String Compression.
// time complexity: O(n)
// space complexity: O(n)