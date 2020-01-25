class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> visited;
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
            if (visited.find(cur) != visited.end()) {
                continue;
            }
            
            if (arr[cur] == 0) {
                return true;
            }
            
            visited.insert(cur);
            q.push(cur + arr[cur]);
            q.push(cur - arr[cur]);
        }
        
        return false;
    }
};


// Runtime: 88 ms, faster than 5.23% of C++ online submissions for Jump Game III.
// Memory Usage: 12.3 MB, less than 100.00% of C++ online submissions for Jump Game III.
// time complexity: O(n)
// space complexity: O(n)