class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int left = 0;
        int right = 0;
        vector<int> count(26, 0); // lowercase
        int max_len = 0;
        
        string s;
        
        return dfs(count, 0, arr, s);
    }
    
    int dfs (vector<int> count, int index, vector<string>& arr, string s) {
        if (index == arr.size())
            return s.length();

        int n = arr.size();
        int i = 0;

        // don't take this string
        int max_length = 0;
        max_length = dfs(count, index + 1, arr, s);

        for (; i < arr[index].length(); ++i) {
            char c = arr[index][i];
            if (count[c - 'a'] > 0) {
                i--;
                break;
            }
            else {
                ++count[c - 'a'];
            }
        }

        // can have this string
        if (i == arr[index].length()) {
            s += arr[index];
            max_length = max(max_length, dfs(count, index + 1, arr, s));
        }

        return max(max_length, 0);
    }
};


// Runtime: 96 ms, faster than 16.67% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// Memory Usage: 85.2 MB, less than 100.00% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// time complexity: O(2^n)
// space complexity: O(2^n)