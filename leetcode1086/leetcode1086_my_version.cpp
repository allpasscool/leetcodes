class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int n = items.size();
        map<int, priority_queue<int>> scores;
        vector<vector<int>> ans;
        
        for (auto &id_and_scores : items) {
            int m = id_and_scores.size();
            
            if (m < 1)
                continue;
            
            int id = id_and_scores[0];
            
            for (int i = 1; i < m; ++i) {
                scores[id].push(id_and_scores[i]);
            }
        }
        
        for (auto &p : scores) {
            int id = p.first;
            auto pq = p.second;
            int avg = 0;
            
            for (int i = 0; i < 5; ++i) {
                avg += pq.top();
                pq.pop();
            }
            
            avg /= 5;
            ans.push_back({id, avg});
        }
        
        return ans;
    }
};


// Runtime: 8 ms, faster than 99.25% of C++ online submissions for High Five.
// Memory Usage: 11.2 MB, less than 87.50% of C++ online submissions for High Five.
// time complexity: O(n)
// space complexity: O(n)