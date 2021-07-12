/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        // step 1: put all interval into List<Interval>
        List<Interval> scheduleList = new ArrayList<>();
        
        for (List<Interval> intervalList : schedule)
        {
            for (Interval interval : intervalList)
            {
                scheduleList.add(interval);
            }
        }
        
        // below are almost the same as leetcode 56
        // sort by start time
        // if start time are same, then sort by end time
        Collections.sort(scheduleList,
                   (Interval i1, Interval i2) -> i1.start != i2.start ? i1.start - i2.start : i1.end - i2.end
                   );
        
        List<Interval> ansList = new ArrayList<>();
        
        int startTime = scheduleList.get(0).start;
        int endTime = scheduleList.get(0).end;
        
        for (Interval interval : scheduleList)
        {
            // can merge interval
            if (interval.start <= endTime)
            {
                endTime = Math.max(interval.end, endTime);
            }
            // they don't overlay
            else
            {
                ansList.add(new Interval(endTime, interval.start));
                startTime = interval.start;
                endTime = interval.end;
            }
        }
        
        return ansList;
    }
}

// Runtime: 17 ms, faster than 22.86% of Java online submissions for Employee Free Time.
// Memory Usage: 51.9 MB, less than 12.70% of Java online submissions for Employee Free Time.
// time complexity: O(n log n)
// space complexity: O(n)