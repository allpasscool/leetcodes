class Solution {
// private:
//     static bool comp(pair<int, int>& p1, pair<int, int>& p2) {
//         return p1.first < p2. first;
//     }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for (vector<int>& edge: times) {
            if (graph.find(edge[0]) == graph.end()) {
                graph[edge[0]] = vector<pair<int, int>> ();
            }
            graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
            // cout << "graph: " << edge[0] << ", " << edge[1] << ", " << edge[2] << endl;
        }
        // cout << "graph[2]: " << graph[2].size() << endl;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        heap.push(make_pair(0, K));
        
        unordered_map<int, int> dist;
        
        while (!heap.empty()) {
            auto p = heap.top();
            heap.pop();
            int d = p.first, node = p.second;
            
            if (dist.find(node) != dist.end()) {
                continue;
            }
            // cout << "node: " << node << endl;
            dist[node] = d;
            
            if (graph.find(node) != graph.end()) {
                for (auto edge: graph[node]) {
                    int nei = edge.first, d2 = edge.second;
                    // cout << "push nei: " << nei << endl;
                    if (dist.find(nei) == dist.end()) {
                        heap.push(make_pair(d + d2, nei));
                        // cout << "push nei: " << nei << endl;
                    }
                }
            }
        }
        
        // cout << "graph[2]: " << graph[2].size() << endl;
        
        if (dist.size() != N) {
            // cout << dist.size();
            return -1;
        }
        
        int ans = 0;
        
        for(auto& p: dist) {
            ans = max(ans, p.second);
        }
        
        return ans;
    }
};
// Runtime: 108 ms, faster than 52.64% of C++ online submissions for Network Delay Time.
// Memory Usage: 28.8 MB, less than 66.67% of C++ online submissions for Network Delay Time.
// time complexity: O(E log E)
// space complexity: O(N + E) the size of the graph O(E), and the size of the other objects used O(N)