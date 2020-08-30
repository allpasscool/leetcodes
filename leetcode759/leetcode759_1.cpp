/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all;
        
        for (const auto intervals : schedule) {
            all.insert(all.end(), intervals.begin(), intervals.end());
        }
        
        sort(begin(all), end(all),
            [](const Interval& a, const Interval& b){
                return a.start < b.start;
            });
            
        vector<Interval> ans;
        int end = all.front().end;
        
        for (const Interval& busy : all) {
            if (busy.start > end) {
                ans.emplace_back(end, busy.start);
            }
            end = max(end, busy.end);
        }
        
        return ans;
    }
};

// Runtime: 56 ms, faster than 90.86% of C++ online submissions for Employee Free Time.
// Memory Usage: 11 MB, less than 53.67% of C++ online submissions for Employee Free Time.
// time complexity: O(n log n)
// space complexity: O(n)
// https://zxi.mytechroad.com/blog/geometry/leetcode-759-employee-free-time/

// // Author: Huahua
// // Running time: 81 ms
// class Solution {
// public:
//     vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
//       vector<Interval> all;
//       for (const auto intervals : schedule)
//         all.insert(all.end(), intervals.begin(), intervals.end());
//       std::sort(all.begin(), all.end(), 
//                 [](const Interval& a, const Interval& b){
//                   return a.start < b.start;
//                 });
//       vector<Interval> ans;
//       int end = all.front().end;
//       for (const Interval& busy : all) {
//         if (busy.start > end) 
//           ans.emplace_back(end, busy.start);  
//         end = max(end, busy.end);
//       }
//       return ans;
//     }
// };