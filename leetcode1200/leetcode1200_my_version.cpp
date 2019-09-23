class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int min_diff = INT_MAX;
        
        for (int i = 1; i < n; ++i) {
            min_diff = min(min_diff, arr[i] - arr[i - 1]);
        }
        
        vector<vector<int>> output;
        
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] == min_diff) {
                vector<int> tmp;
                tmp.push_back(arr[i-1]);
                tmp.push_back(arr[i]);
                output.push_back(tmp);
            }
        }
        
        return output;
    }
};

// Runtime: 116 ms, faster than 100.00% of C++ online submissions for Minimum Absolute Difference.
// Memory Usage: 17.9 MB, less than 100.00% of C++ online submissions for Minimum Absolute Difference.
// time complexity: O(n log n)
// space complexity: O(1)