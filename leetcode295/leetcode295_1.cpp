class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (store.empty()) {
            store.push_back(num);
        }
        else {
            store.insert(lower_bound(store.begin(), store.end(), num), num);
        }
    }
    
    double findMedian() {
        int n = store.size();
        
        if (n % 2 == 1) {
            return store[n / 2];
        }
        else {
            return ((double) (store[n / 2 - 1] + store[n / 2]) / 2);
        }
    }
private:
    vector<int> store;
};


// Runtime: 292 ms, faster than 8.04% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 42.5 MB, less than 82.61% of C++ online submissions for Find Median from Data Stream.
// time complexity: add O(log n + n) find O(1)
// space complexity: O(n)

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
