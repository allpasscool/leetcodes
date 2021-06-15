class MovingAverage {
    Queue<Integer> q;
    int sum;
    int windowSize;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        q = new LinkedList<Integer>();
        sum = 0;
        windowSize = size;
    }

    public double next(int val) {
        q.add(val);
        sum += val;

        if (q.size() > windowSize) {
            sum -= q.poll();
        }

        return (double) sum / (double) q.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size); double param_1 = obj.next(val);
 */

// Runtime: 43 ms, faster than 91.87% of Java online submissions for Moving
// Average from Data Stream.
// Memory Usage: 44.1 MB, less than 19.44% of Java online submissions for Moving
// Average from Data Stream.
// time complexity: O(1)
// space complexity: O(window size)