class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        lo_median = data.end();
        hi_median = data.end();
    }
    
    void addNum(int num) {
        const size_t n = data.size(); // store previous size
        data.insert(num);
        
        if (n == 0) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n % 2 == 1) {
            // odd size befor (i.e. lo == hi), even size now(i.e. hi = lo + 1)
            
            if (num < *lo_median) // num < lo
                lo_median--;
            else                  // num >= hi
                hi_median++;      // insertion at end of equal range
        }
        else {
            // even size befor (i.e. hi = lo + 1), odd size now (i.e. lo == hi)
            
            if (num > *lo_median && num < *hi_median) {
                lo_median++;    // num is between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median) {   // num inserted after hi
                lo_median++;
            }
            else {                          // num <= lo < hi
                hi_median--;                // insertion at end of equal rang spoils lo
                lo_median = hi_median;
            }
        }
    }
    
    double findMedian() {
        return (*lo_median + *hi_median) * 0.5;
    }
private:
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;
};

// Runtime: 156 ms, faster than 79.12% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 45 MB, less than 26.09% of C++ online submissions for Find Median from Data Stream.
// time complexity: insertion O(log n) find O(1)
// space complexity: O(n) 

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */