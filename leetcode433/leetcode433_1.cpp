class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        
        unordered_set<string> visited;
        visited.insert(start);
        
        int mutations = 0;
        
        while (!q.empty()) {
            int n = q.size();
            
            // bfs
            for (int i = 0; i < n; ++i) {
                string curr = std::move(q.front());
                q.pop();
                
                // find it
                if (curr == end)
                    return mutations;
                
                // all next possible
                for (const string& gene: bank) {
                    if (visited.find(gene) != visited.end()
                       || !validMutation(curr, gene)) {
                        continue;
                    }
                    
                    visited.insert(gene);
                    q.push(gene);
                }
            }
            
            ++mutations;
        }
        
        return -1;
    }
    
private:
    bool validMutation(const string& curr, const string& gene) {
        int count = 0;
        for (int i = 0; i < curr.length(); ++i) {
            if (curr[i] != gene[i] && count++)
                return false;
        }
        
        return true;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Genetic Mutation.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Minimum Genetic Mutation.
// time complexity: O(n^2)
// space complexity: O(n)