class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        for (int num : nums)
            pq.push(num);

        while (pq.size() > k)
            pq.pop();
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Runtime: 37 ms, faster than 66.42% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 19.9 MB, less than 61.16% of C++ online submissions for Kth Largest Element in a Stream.
// time complexity: add O(log k)
// space complexity: O(k)