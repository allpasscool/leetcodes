class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int count = 0;
        queue<int> q;
        
        for (int i = 0; i < M.size(); i++) {
            if (!visited[i]) {
                q.push(i);
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    visited[top] = true;
                    for (int j = 0; j < M.size(); j++) {
                        if (M[top][j] == 1 && !visited[j]) {
                            q.push(j);
                        }
                    }
                }
                count++;
            }
        }
        
        return count;
    }
};
// Runtime: 32 ms, faster than 18.46% of C++ online submissions for Friend Circles.
// Memory Usage: 11 MB, less than 54.55% of C++ online submissions for Friend Circles.
// time complexity: O(n^2)
// space complexity: O(n)