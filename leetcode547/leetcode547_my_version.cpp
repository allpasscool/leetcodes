class Solution {
private:
    vector<int> parent;
    void merge(int x, int y) {
        if (parent[x] == x && parent[y] == y) {
            parent[x] = y;
        }
        else if (parent[x] == x) {
            parent[x] = find(parent[y]);
        }
        else if (parent[y] == y) {
            parent[y] = find(parent[x]);
        }
        else {
            parent[find(parent[x])] = find(parent[y]);
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n < 2) {
            return n;
        }
        
        
        // all node point to itself
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1 && parent[i] != parent[j]) {
                    merge(i, j);
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                ans++;
            }
        }
        
        return ans;
    }
};
// Runtime: 20 ms, faster than 83.00% of C++ online submissions for Friend Circles.
// Memory Usage: 10.9 MB, less than 81.82% of C++ online submissions for Friend Circles.
// time complexity: O(n^3)
// space complexity: O(n)