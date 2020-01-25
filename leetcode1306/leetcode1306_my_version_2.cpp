class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited (arr.size(), false);
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // out of range
            if (cur >= arr.size() || cur < 0) {
                continue;
            }
            
            // visited
            if (visited[cur]) {
                continue;
            }
            
            if (arr[cur] == 0) {
                return true;
            }
            
            visited[cur] = true;
            q.push(cur + arr[cur]);
            q.push(cur - arr[cur]);
        }
        
        return false;
    }
};


// Runtime: 72 ms, faster than 7.93% of C++ online submissions for Jump Game III.
// Memory Usage: 12.4 MB, less than 100.00% of C++ online submissions for Jump Game III.
// time complexity: O(n)
// space complexity: O(n)