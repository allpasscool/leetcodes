class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();
        
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? (double) lo.top() : (double)(lo.top() + hi.top()) / 2;
    }
private:
    priority_queue<int> lo; // max heap
    priority_queue<int, vector<int>, greater<int>> hi; // min heap
};

// Runtime: 168 ms, faster than 49.19% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 42.5 MB, less than 95.65% of C++ online submissions for Find Median from Data Stream.
// time complexity: O(log n)
// space complexity: O(n)

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

