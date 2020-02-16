class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(begin(events), end(events));
        
        int i = 0, count = 0, n = events.size();
        
        for (int d = 1; d <= 1e5; ++d) {
            // events starts at d
            while (i < n && events[i][0] == d) {
                pq.push(events[i][1]);
                ++i;
            }
            
            //drop events no time to attend
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            
            // attend one event this day
            if (!pq.empty()) {
                pq.pop();
                ++count;
            }
        }
        
        return count;
    }
};


// Runtime: 336 ms, faster than 45.45% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// Memory Usage: 45.7 MB, less than 100.00% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// time complexity: O(n log n)
// space complexity: O(n)

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
// int maxEvents(vector<vector<int>>& A) {
//     priority_queue <int, vector<int>, greater<int>> pq;
//     sort(A.begin(), A.end());
//     int i = 0, res = 0, n = A.size();
//     for (int d = 1; d <= 100000; ++d) {
//         while (i < n && A[i][0] == d)
//             pq.push(A[i++][1]);
//         while (pq.size() && pq.top() < d)
//             pq.pop();
//         if (pq.size()) {
//             pq.pop();
//             ++res;
//         }
//     }
//     return res;
// }

