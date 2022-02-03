class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() || num <= maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

        // adjust size
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (minheap.empty() && maxheap.empty())
            return 0;
        else if (minheap.empty())
            return maxheap.top();
        else if (maxheap.size() == minheap.size() + 1)
            return maxheap.top();
        else if (minheap.size() == maxheap.size() + 1)
            return minheap.top();
        else
            return ((double)minheap.top() + (double)maxheap.top()) / 2;
    }

private:
    // for smaller half
    priority_queue<int> maxheap;
    // for larger half
    priority_queue<int, vector<int>, greater<int>> minheap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Runtime: 300 ms, faster than 80.28% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 117.1 MB, less than 20.41% of C++ online submissions for Find Median from Data Stream.
// time complexity: add O(log n) find O(1)
// space complexity: O(n)