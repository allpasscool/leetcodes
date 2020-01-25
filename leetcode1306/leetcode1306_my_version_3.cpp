class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        
        return dfs(arr, start, visited);
    }
    
private:
    bool dfs (vector<int>& arr, int start, vector<bool>& visited) {
        if (arr[start] == 0) {
            return true;
        }
        
        visited[start] = true;
        
        if ( ((start + arr[start]) < arr.size())
            && !visited[start + arr[start]] 
           && dfs(arr, start + arr[start], visited)) {
            return true;
        }
        
        if ( ((start - arr[start]) >= 0)
            && !visited[start - arr[start]]
           && dfs(arr, start - arr[start], visited)) {
            return true;
        }
        
        return false;
    }
};


// Runtime: 64 ms, faster than 13.34% of C++ online submissions for Jump Game III.
// Memory Usage: 12.3 MB, less than 100.00% of C++ online submissions for Jump Game III.
// time complexity: O(n)
// space complexity: O(n)