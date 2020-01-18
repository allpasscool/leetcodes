class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> hashflights; // hashflights[src] = {dst, cost}
        
        for (auto f : flights) {
            hashflights[f[0]].push_back({f[1], f[2]});
        }
        
        int ans = INT_MAX;
        queue<pair<int, int>> q; // {pos. current cost};
        q.push({src, 0});
        int step = 0;
        
        while (!q.empty()) {
            int size = q.size();
            // every possible move one step
            for (int i = 0; i < size; ++i) {
                int pos = q.front().first;
                int cur_cost = q.front().second;
                q.pop();
                
                for (auto f : hashflights[pos]) {
                    int next = f.first;
                    int cost = f.second;
                    
                    // won't get better solution
                    if (ans <= cur_cost + cost) {
                        continue;
                    }
                    if (next == dst) {
                        ans = min(ans, cur_cost + cost);
                        continue;
                    }
                    
                    q.push({next, cur_cost + cost});
                }
            }
            
            ++step;
            if (step > K) {
                break;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

// Runtime: 16 ms, faster than 81.21% of C++ online submissions for Cheapest Flights Within K Stops.
// Memory Usage: 11.8 MB, less than 85.71% of C++ online submissions for Cheapest Flights Within K Stops.
// time complexity: O(n^(K+1))
// space complexity: O(n^(K + 1))

// // Author: Huahua
// // Running time: 20 ms
// class Solution {
// public:
//   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
//     unordered_map<int, vector<pair<int,int>>> g;
//     for (const auto& e : flights)
//       g[e[0]].emplace_back(e[1], e[2]);
    
//     int ans = INT_MAX;
//     queue<pair<int,int>> q;
//     q.push({src, 0});
//     int steps = 0;
    
//     while (!q.empty()) {
//       int size = q.size();
//       while (size--) {
//         int curr = q.front().first;
//         int cost = q.front().second;
//         q.pop();
//         if (curr == dst) 
//           ans = min(ans, cost);
//         for (const auto& p : g[curr]) {
//           if (cost + p.second > ans) continue; // Important: prunning          
//           q.push({p.first, cost + p.second});
//         }
//       }
//       if (steps++ > K) break;
//     }
    
//     return ans == INT_MAX ? - 1 : ans;
//   }
// };
