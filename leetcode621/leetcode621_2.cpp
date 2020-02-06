class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26);
        
        for (auto t : tasks) {
            ++counts[t - 'A'];
        }
        
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                pq.push({counts[i], i + 'A'});
            }
        }
        
        int ans = 0;
        int cycle = n + 1;
        
        // one cycle
        while (!pq.empty()) {
            int time = 0;
            vector<pair<int, char>> tmp;
            
            // assign tasks
            for (int i = 0; i < cycle; ++i) {
                // do this task
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    tmp.back().first--;
                    ++time;
                }
                else {
                    break;
                }
            }
            
            // put back for next cycle
            for (auto t : tmp) {
                if (t.first > 0) {
                    pq.push(t);
                }
            }
            
            // assign idles? last cycle?
            ans += pq.empty() ? time : cycle;
        }
        
        return ans;
    }
};

// Runtime: 140 ms, faster than 30.77% of C++ online submissions for Task Scheduler.
// Memory Usage: 24.3 MB, less than 6.38% of C++ online submissions for Task Scheduler.
// time complexity: O(n + n * m), m is the cycle time
// space complexity: O(n)
// https://leetcode.com/problems/task-scheduler/discuss/104493/C%2B%2B-Java-Clean-Code-Priority-Queue

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         unordered_map<char, int> counts;
//         for (char t : tasks) {
//             counts[t]++;
//         }
//         priority_queue<pair<int, char>> pq;
//         for (pair<char, int> count : counts) {
//             pq.push(make_pair(count.second, count.first));
//         }
//         int alltime = 0;
//         int cycle = n + 1;
//         while (!pq.empty()) {
//             int time = 0;
//             vector<pair<int, char>> tmp;
//             for (int i = 0; i < cycle; i++) {
//                 if (!pq.empty()) {
//                     tmp.push_back(pq.top());
//                     pq.pop();
//                     time++;
//                 }
//             }
//             for (auto t : tmp) {
//                 if (--t.first) {
//                     pq.push(t);
//                 }
//             }
//             alltime += !pq.empty() ? cycle : time;
//         }
//         return alltime;
//     }
// };

