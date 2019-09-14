class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> forward(n, 0), backward(n, 0);
        
        int count = 0;
        int output = INT_MIN;
        for (int i = 0; i < n; i++) {
            count = max(count, 0) + arr[i];
            forward[i] = count;
            output = max(output, count);
        }
        
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            count = max(count, 0) + arr[i];
            backward[i] = count;
            output = max(output, count);
        }
        
        for (int i = 0; i < n - 2; i++) {
            output = max(forward[i] + backward[i + 2], output);
        }
        
        return output;
    }
};
// Runtime: 36 ms, faster than 97.53% of C++ online submissions for Maximum Subarray Sum with One Deletion.
// Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for Maximum Subarray Sum with One Deletion.
// time complexity: O(n)
// space complexity: O(n)