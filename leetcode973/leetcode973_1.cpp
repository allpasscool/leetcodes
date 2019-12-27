class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), comp);
        
        return vector<vector<int>> (points.begin(), points.begin() + K);
    }

private:
    static bool comp(vector<int>& p1, vector<int>& p2) {
        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
    }
};


// Runtime: 264 ms, faster than 50.92% of C++ online submissions for K Closest Points to Origin.
// Memory Usage: 36.8 MB, less than 98.44% of C++ online submissions for K Closest Points to Origin.
// time complexity: O(n log K)
// space copmlexity: O(1)


// https://leetcode.com/problems/k-closest-points-to-origin/discuss/221532/C%2B%2B-STL-quickselect-priority_queue-and-multiset
// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//         partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
//             return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
//         });
//         return vector<vector<int>>(points.begin(), points.begin() + K);
//     }
// };