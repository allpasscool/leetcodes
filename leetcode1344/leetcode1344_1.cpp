class Solution {
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


// Runtime: 44 ms, faster than 66.67% of C++ online submissions for Jump Game V.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Jump Game V.
// time complexity: O(n log n + n * d)
// space complexity: O(n)
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1344-jump-game-v/