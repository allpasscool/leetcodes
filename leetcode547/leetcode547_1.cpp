class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && visited[j] == false) {
                visited[j] = true;
                dfs(M, visited, j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int count = 0;
        
        for (int i = 0; i < M.size(); i++) {
            if(!visited[i]) {
                dfs(M, visited, i);
                count++;
            }
        }
        
        return count;
    }
};
// Runtime: 20 ms, faster than 83.00% of C++ online submissions for Friend Circles.
// Memory Usage: 10.9 MB, less than 81.82% of C++ online submissions for Friend Circles.
// time complexity: O(n^2)
// space complexity: O(n)