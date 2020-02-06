class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task(26);
        
        for (auto t : tasks) {
            ++task[t - 'A'];
        }
        
        int max_count = *max_element(task.begin(), task.end());
        
        int ans = (max_count - 1) * (n + 1); // max_count - 1 slots
        
        for (auto t : task) {
            if (t == max_count) {
                ++ans;
            }
        }
        
        return max(ans, (int)tasks.size());
    }
    
};


// Runtime: 52 ms, faster than 95.92% of C++ online submissions for Task Scheduler.
// Memory Usage: 9.7 MB, less than 87.23% of C++ online submissions for Task Scheduler.
// time complexity: O(n)
// space complexity: O(1)
// http://zxi.mytechroad.com/blog/greedy/leetcode-621-task-scheduler/

// // Author: Huahua
// // Runtime: 56 ms
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> count(26, 0);        
//         for (const char task : tasks) 
//             ++count[task - 'A'];
//         const int max_count = *max_element(count.begin(), count.end());
//         size_t ans = (max_count - 1) * (n + 1);
//         ans += count_if(count.begin(), count.end(),
//                         [max_count](int c){ return c == max_count; });
//         return max(tasks.size(), ans);
//     }
// };