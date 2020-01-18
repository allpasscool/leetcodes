class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for (auto f : flights) {
            hashflights[f[0]].push_back({f[1], f[2]});
        }
        
        
        int ans = INT_MAX;
        vector<bool> visited(n, false);
        visited[src] = true;
        
        // stop K times means flight K + 1 times
        dfs(visited, src, dst, K + 1, ans, 0);
        
        
        return ans == INT_MAX ? -1 : ans;
    }
    
private:
    unordered_map<int, vector<pair<int, int>>> hashflights; // hashflights[src] = {dst, cost}
    
    void dfs(vector<bool> visited, int src, int& dst, int K, int& ans, int cur_cost) {
        
        // arrive dst
        if (src == dst) {
            ans = min(ans, cur_cost);
            return;
        }
        if (K == 0) {
            return;
        }
        
        for (auto& p : hashflights[src]) {
            int next = p.first;
            int cost = p.second;
            
            // visited befor
            if (visited[next]) {
                continue;
            }
            // won't get better solution
            if (cur_cost + cost > ans) {
                continue;
            }
            
            visited[next] = true;
            dfs(visited, next, dst, K - 1, ans, cur_cost + cost);
            visited[next] = false;
        }
        
        return;
    }
};


// Runtime: 104 ms, faster than 9.68% of C++ online submissions for Cheapest Flights Within K Stops.
// Memory Usage: 15.4 MB, less than 50.00% of C++ online submissions for Cheapest Flights Within K Stops.
// time complexity: O(n^(k+1))
// space complexity: O(k+1) deep
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-787-cheapest-flights-within-k-stops/


// // Author: Huahua
// // Running time: 36 ms
// class Solution {
// public:
//   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//     g_.clear();  
//     for (const auto& e : flights)
//       g_[e[0]].emplace_back(e[1], e[2]);
//     vector<int> visited(n, 0);
//     visited[src] = 1;
//     int ans = INT_MAX;
//     dfs(src, dst, K + 1, 0, visited, ans);
//     return ans == INT_MAX ? - 1 : ans;
//   }
// private:
//   unordered_map<int, vector<pair<int,int>>> g_;
  
//   void dfs(int src, int dst, int k, int cost, vector<int>& visited, int& ans) {
//     if (src == dst) {
//       ans = cost;
//       return;
//     }
    
//     if (k == 0) return;    
    
//     for (const auto& p : g_[src]) {
//       if (visited[p.first]) continue; // do not visit the same city twice.
//       if (cost + p.second > ans) continue; // IMPORTANT!!! prunning 
//       visited[p.first] = 1;
//       dfs(p.first, dst, k - 1, cost + p.second, visited, ans);
//       visited[p.first] = 0;
//     }
//   }
// };
