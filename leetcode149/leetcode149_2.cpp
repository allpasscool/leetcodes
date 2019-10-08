class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int output = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> lines;
            int duplicate = 1;
            int local_max = 0;
            
            for (int j = i + 1; j < n; ++j) {
                if (points[j][0] == points[i][0] 
                   && points[j][1] == points[i][1]) {
                    ++duplicate;
                }
                else {
                    int x_diff = points[j][0] - points[i][0];
                    int y_diff = points[j][1] - points[i][1];
                    int gcd = __gcd(x_diff, y_diff);
                    x_diff /= gcd;
                    y_diff /= gcd;
                    string line = to_string(x_diff) + '_' + to_string(y_diff);
                    
                    ++lines[line];
                    local_max = max(local_max, lines[line]);
                }
            }
            
            output = max(output, local_max + duplicate);
        }
        
        return output;
    }
};

// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n = points.size(), ans = 0;
//         for (int i = 0; i < n; i++) {
//             unordered_map<string, int> counter;
//             int dup = 1;
//             for (int j = i + 1; j < n; j++) {
//                 if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
//                     dup++;
//                 } else {
//                     int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1], g = __gcd(dx, dy);
//                     counter[to_string(dx / g) + '_' + to_string(dy / g)]++;
//                 }
//             }
//             ans = max(ans, dup);
//             for (auto p : counter) {
//                 ans = max(ans, p.second + dup);
//             }
//         }
//         return ans;
//     }
// };


// Runtime: 24 ms, faster than 42.73% of C++ online submissions for Max Points on a Line.
// Memory Usage: 12.4 MB, less than 35.71% of C++ online submissions for Max Points on a Line.
// time complexity: O(n^2)
// space complexity: O(n)
// https://leetcode.com/problems/max-points-on-a-line/discuss/47124/C%2B%2B-slope-counter