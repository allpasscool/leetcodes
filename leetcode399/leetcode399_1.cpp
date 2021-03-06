class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // g[A][B] = k -> A / B = k
        unordered_map<string, unordered_map<string, double>> g;
        for (int i = 0; i < equations.size(); i++) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }
        
        vector<double> ans;
        for (const vector<string>& p: queries) {
            const string& X = p[0];
            const string& Y = p[1];
            if (!g.count(X) || !g.count(Y)) {
                ans.push_back(-1.0);
                continue;
            }
            
            unordered_set<string> visited;
            ans.push_back(divide(X, Y, g, visited));
        }
        
        return ans;
    };
    
private:
    // get result of A / B
    double divide(const string& A, const string& B, 
                 unordered_map<string, unordered_map<string, double>> g,
                 unordered_set<string>& visited) {
        if (A == B) {
            return 1.0;
        }
        
        visited.insert(A);
        for (const pair<string, double>& p: g[A]) {
            const string& C = p.first;
            if (visited.count(C)) {
                continue;
            }
            
            double d = divide(C, B, g, visited); // d = C / B
            // A / B = C / B * A / C;
            if (d > 0) {
                return d * g[A][C];
            }
        }
        
        return -1.0;
    }
};
// Runtime: 4 ms, faster than 59.15% of C++ online submissions for Evaluate Division.
// Memory Usage: 11.5 MB, less than 5.55% of C++ online submissions for Evaluate Division.
// time complexity: O(e + q * e)
// space complexity: O(e)
// https://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/