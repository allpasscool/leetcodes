class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> count(26, 0); // lowercase
        // int max_len = 0;
        
        // string s;
        
        return dfs(count, 0, arr);
    }
    
    int dfs (vector<int> count, int index, vector<string>& arr) {
        if (index == arr.size()) {
            int ans = 0;
            for (auto num: count)
                ans += num;
            return ans;
        }

        int n = arr.size();
        int i = 0;

        // don't take this string
        int max_length = 0;
        max_length = dfs(count, index + 1, arr);

        for (; i < arr[index].length(); ++i) {
            char c = arr[index][i];
            if (count[c - 'a'] > 0) {
                return max_length;
            }
            else {
                ++count[c - 'a'];
            }
        }

        // can have this string
        if (i == arr[index].length()) {
            // s += arr[index];
            max_length = max(max_length, dfs(count, index + 1, arr));
        }

        return max_length;
    }
};


// Runtime: 96 ms, faster than 37.91% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// Memory Usage: 84 MB, less than 100.00% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// time complexity: O(2^n)
// space complexity: O(2^n)