class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> adj_matrix(N + 1, vector<int> (N + 1, INT_MAX));
        
        // make adjancy matrix
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0], target = times[i][1], cost = times[i][2];
            adj_matrix[source][target] = min(cost, adj_matrix[source][target]);
        }
        
        vector<int> cost(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        
        cost[K] = 0;
        visited[K] = true;
        int max_cost = 0;
        queue<int> q;
        q.push(K);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // what cur node points to
            for (int i = 1; i <= N; i++) {
                // cur points to i
                if (adj_matrix[cur][i] != INT_MAX) {
                    // if we need to update cost from source N to node i
                    if (cost[cur] + adj_matrix[cur][i] < cost[i]) {
                        q.push(i);
                        visited[i] = true;
                        cost[i] = cost[cur] + adj_matrix[cur][i];
                    }
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                return -1;
            }
            max_cost = max(max_cost, cost[i]);
        }
        
        return max_cost;
    }
};
// Runtime: 84 ms, faster than 93.95% of C++ online submissions for Network Delay Time.
// Memory Usage: 24.7 MB, less than 94.44% of C++ online submissions for Network Delay Time.
// time complexity: O(n ^ n)
// space complexity: O(n ^ 2)