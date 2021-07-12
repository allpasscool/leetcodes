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
        
        LinkedList<Interval> merged = new LinkedList<>();
        LinkedList<Interval> ans = new LinkedList<>();
        
        for (Interval interval : scheduleList) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.isEmpty() || merged.getLast().end < interval.start) {
                if (merged.isEmpty() == false)
                {
                    ans.add(new Interval(merged.getLast().end, interval.start));
                }
                
                merged.add(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.getLast().end = Math.max(merged.getLast().end, interval.end);
            }
        }
        
        return ans;
    }
}

// Runtime: 17 ms, faster than 22.86% of Java online submissions for Employee Free Time.
// Memory Usage: 51.9 MB, less than 12.70% of Java online submissions for Employee Free Time.
// time complexity: O(n log n)
// space complexity: O(n)