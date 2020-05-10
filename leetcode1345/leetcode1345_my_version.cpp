class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int target = arr[n - 1];
        unordered_map<int, vector<int>> num_index;
        
        // insert numbers into hashmap
        for(int i = 0; i < n; ++i) {
            num_index[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        
        int steps = 0;
        vector<bool> visited(n);
        
        while (!q.empty()) {
            int count = q.size();
            
            // bfs
            for (int i = 0; i < count; ++i) {
                int cur = q.front();
                q.pop();
                
                // target?
                if (cur == n - 1) {
                    return steps;
                }
                
                // visited?
                if (visited[cur]) {
                    continue;
                }
                visited[cur] = true;
                
                // arr[i] == arr[j] && i != j
                for (int j = num_index[arr[cur]].size() - 1; j >= 0; j--) {
                    int idx = num_index[arr[cur]][j];
                    if (cur != idx) {
                        q.push(idx);
                    }
                }
                // clear num_index[arr[cur]]
                // this is the most important step
                num_index[arr[cur]].clear();
                
                // i + 1
                if ((cur + 1 < n) && !visited[cur + 1]) {
                    q.push(cur + 1);
                }
                
                // i - 1
                if ((cur - 1 >= 0) && !visited[cur - 1]) {
                    q.push(cur - 1);
                }
                
            }
            
            ++steps;
        }
        
        
        return -1;
    }
};


// Runtime: 256 ms, faster than 51.66% of C++ online submissions for Jump Game IV.
// Memory Usage: 46.5 MB, less than 100.00% of C++ online submissions for Jump Game IV.
// time complexity: O(n)
// space complexity: O(n)


// class Solution {
// public:
//     int minJumps(vector<int>& arr) {
//         int n = arr.size();
//         unordered_map<int, vector<int>> indicesOfValue;
// 
//         for (int i = 0; i < n; i++)
//             indicesOfValue[arr[i]].push_back(i);
// 
//         vector<bool> visited(n); visited[0] = true;
//         queue<int> q; q.push(0);
//         int step = 0;
// 
//         while (!q.empty()) {
//             for (int size = q.size(); size > 0; --size) {
//                 int i = q.front(); q.pop();
// 
//                 if (i == n - 1) return step; // Reached to last index
// 
//                 vector<int>& next = indicesOfValue[arr[i]];
// 
//                 next.push_back(i - 1); next.push_back(i + 1);
// 
//                 for (int j : next) {
//                     if (j >= 0 && j < n && !visited[j]) {
//                         visited[j] = true;
//                         q.push(j);
//                     }
//                 }
// 
//                 next.clear(); // avoid later lookup indicesOfValue arr[i]
//             }
//             step++;
//         }
//         return 0;
//     }
// };