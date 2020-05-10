lass Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        heights = vector<pair<int, int>> (n);
        
        for (int i = 0; i < n; ++i) {
            heights[i] = {arr[i], i};
        }
        
        sort(begin(heights), end(heights));
        
        vector<int> dp(n, 1);
        
        for (auto [h, index] : heights) {
            // front
            for (int i = index + 1; i <= min(n - 1, index + d) && arr[index] > arr[i]; ++i) {
                dp[index] = max(dp[index], dp[i] + 1);
            }
            
            // back
            for (int i = index - 1; i >= max(0, index - d) && arr[index] > arr[i]; i--) {
                dp[index] = max(dp[index], dp[i] + 1);
            }
        }
        
        return *max_element(begin(dp), end(dp));
    }
    
private:
    vector<pair<int, int>> heights; // heigh and index
};


// Runtime: 84 ms, faster than 37.29% of C++ online submissions for Jump Game V.
// Memory Usage: 15.6 MB, less than 100.00% of C++ online submissions for Jump Game V.
// time complexity: O(n)
// space complexity: O(n)
