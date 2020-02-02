class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            ans = max(ans, dfs(arr, d, i) + 1);
        }
        
        return ans;
    }
    
private:
    int dfs(vector<int>& arr, int d, int cur) {
        if (memo.find(cur) != memo.end()) {
            return memo[cur];
        }
        
        // jump front
        int front = 0;
        for (int i = 1; i <=d && (cur + i) < arr.size(); ++i) {
            if (arr[cur + i] >= arr[cur]) {
                break;
            }
            
            front = max(front, dfs(arr, d, cur + i) + 1);
        }
        
        // jump back
        int back = 0;
        for (int i = 1; i <= d && (cur - i) >= 0; ++i) {
            if (arr[cur - i] >= arr[cur]) {
                break;
            }
            
            back = max(back, dfs(arr, d, cur - i) + 1);
        }
        
        memo[cur] = max(front, back);
        
        return memo[cur];
    }
    
    unordered_map<int, int> memo; // index, jump ans
};


// Runtime: 136 ms, faster than 66.67% of C++ online submissions for Jump Game V.
// Memory Usage: 14.8 MB, less than 100.00% of C++ online submissions for Jump Game V.
// time complexity: O(n * d)
// space complexity: O(n)