class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // the value, array list, are the courses requires take key(course)
        HashMap<Integer, List<Integer>> prereq = new HashMap<>();
        HashMap<Integer, Integer> prereq_count = new HashMap<>();
        int n = prerequisites.length;
        
        for (int i = 0; i < n; i++) {
            // before take course, you have to take pre first
            // add to prereq
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            
            // add to prereq
            if (prereq.get(pre) == null)
                prereq.put(pre, new ArrayList<Integer>());
            prereq.get(pre).add(course);
            // add pre count for course
            prereq_count.put(course, prereq_count.getOrDefault(course, 0) + 1);
        }
        
        // find all courses don't need to take pre courses
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < numCourses; i++) {
            if (prereq_count.get(i) == null) {
                q.add(i);
            }
        }
        
        // take courses until can't take any more
        while (!q.isEmpty()) {
            int cur = q.poll();
            
            // courses ask for course 'cur'
            List<Integer> next = prereq.get(cur);
            if (next == null)
                continue;
            
            for (Integer next_course : next) {
                prereq_count.put(next_course, prereq_count.get(next_course) - 1);
                
                // all pre courses have taken
                if (prereq_count.get(next_course) == 0)
                    q.add(next_course);
            }
        }
        
        // check whether all courses can be taken
        for (int i = 0; i < numCourses; i++) {
            if (prereq_count.get(i) != null && prereq_count.get(i) != 0)
                return false;
        }
        
        return true;
    }
}

// Runtime: 8 ms, faster than 28.58% of Java online submissions for Course Schedule.
// Memory Usage: 39.4 MB, less than 65.91% of Java online submissions for Course Schedule.
// time complexity: O(n * m), n is number of courses and m is the max number of a course's prerequisites number
// space compleixty: O(n)