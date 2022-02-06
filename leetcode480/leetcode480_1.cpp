class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> medians;
        unordered_map<int, int> hash_table;
        priority_queue<int> lo;                            // max heap
        priority_queue<int, vector<int>, greater<int>> hi; // min heap

        int i = 0; // index of current incoming element being processed

        // initialize the heaps
        while (i < k)
            lo.push(nums[i++]);
        for (int j = 0; j < k / 2; j++)
        {
            hi.push(lo.top());
            lo.pop();
        }

        while (true)
        {
            // get median of current window
            medians.push_back(k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

            if (i >= nums.size())
                break; // break if all elements processed

            int out_num = nums[i - k], // outgoing element
                in_num = nums[i++],    // incoming element
                balance = 0;           // balance factor

            // number `out_num` exits window
            balance += (out_num <= lo.top() ? -1 : 1);
            hash_table[out_num]++;

            // number `in_num` enters window
            if (!lo.empty() && in_num <= lo.top())
            {
                balance++;
                lo.push(in_num);
            }
            else
            {
                balance--;
                hi.push(in_num);
            }

            // re-balance heaps
            if (balance < 0)
            { // `lo` needs more valid elements
                lo.push(hi.top());
                hi.pop();
                balance++;
            }
            if (balance > 0)
            { // `hi` needs more valid elements
                hi.push(lo.top());
                lo.pop();
                balance--;
            }

            // remove invalid numbers that should be discarded from heap tops
            while (hash_table[lo.top()])
            {
                hash_table[lo.top()]--;
                lo.pop();
            }
            while (!hi.empty() && hash_table[hi.top()])
            {
                hash_table[hi.top()]--;
                hi.pop();
            }
        }

        return medians;
    }
};

// Runtime: 70 ms, faster than 50.61% of C++ online submissions for Sliding Window Median.
// Memory Usage: 14.6 MB, less than 82.41% of C++ online submissions for Sliding Window Median.
// time complexity: O(n * log k).  O(2 * n log k) + O(n-k) ≈ O(n log k)
// space complexity: O(k)+O(n)≈O(n)