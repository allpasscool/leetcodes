class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2)
            return n;
        
        int output = 0;
        
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> lines;
            int local_max = 0, overlap = 0, vertical = 0;
            
            for (int j = i + 1; j < n; ++j) {
                // overlap
                if (points[j][0] == points[i][0]
                   && points[j][1] == points[i][1]) {
                    ++overlap;
                    continue;
                }
                else if (points[j][0] == points[i][0]) 
                    ++vertical;
                else {
                    int x_diff = points[j][0] - points[i][0];
                    int y_diff = points[j][1] - points[i][1];
                    int gcd = __gcd(x_diff, y_diff);
                    
                    x_diff /= gcd;
                    y_diff /= gcd;
                    
                    ++lines[{x_diff, y_diff}];
                    local_max = max(local_max, lines[{x_diff, y_diff}]);
                }
                
                local_max = max(local_max, vertical);
            }
            
            output = max(output, local_max + overlap + 1);
        }
        
        return output;
    }
};

// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         if(points.size()<2) return points.size();
        
//         int result=0;
        
//         for(int i=0; i<points.size(); i++) {
            
//             map<pair<int, int>, int> lines;
//             int localmax=0, overlap=0, vertical=0;
            
//             for(int j=i+1; j<points.size(); j++) {
                
//                 if(points[j][0]==points[i][0] && points[j][1]==points[i][1]) {
                    
//                     overlap++;
//                     continue;
//                 }
//                 else if(points[j][0]==points[i][0]) vertical++;
//                 else {
                    
//                     int a=points[j][0]-points[i][0], b=points[j][1]-points[i][1];
//                     int gcd=__gcd(a, b);
                    
//                     a/=gcd;
//                     b/=gcd;
                    
//                     lines[make_pair(a, b)]++;
//                     localmax=max(lines[make_pair(a, b)], localmax);
//                 }

//                 localmax=max(vertical, localmax);
//             }
            
//             result=max(result, localmax+overlap+1);
//         }
        
//         return result;
//     }
// };



// Runtime: 16 ms, faster than 65.68% of C++ online submissions for Max Points on a Line.
// Memory Usage: 10.8 MB, less than 64.29% of C++ online submissions for Max Points on a Line.
// time complexity: O(n^2)
// space complexity: O(n^2) for lines
// https://leetcode.com/problems/max-points-on-a-line/discuss/47106/C%2B%2B-O(n2)-solution-for-your-reference