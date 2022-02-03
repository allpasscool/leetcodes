class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int maxNum = nums[0];

        // get max number
        for (auto num : nums)
            maxNum = max(maxNum, num);

        // length of max number in a binary representation
        int L = 0;
        for (int i = maxNum; i > 0; i /= 2)
            L++;

        int maxXor = 0, currXor;
        unordered_set<int> prefixes;

        for (int i = L - 1; i >= 0; i--)
        {
            // go to the next bit by the left shift
            maxXor <<= 1;
            // set 1 in the smallest bit
            currXor = maxXor | 1;
            prefixes.clear();
            // compute all possible prefixes
            // of length (L - i) in binary representation
            for (int num : nums)
                prefixes.insert(num >> i);
            // Update maxXor, if two of these prefixes could result in currXor.
            // Check if p1^p2 == currXor, i.e. p1 == currXor^p2.
            for (int p : prefixes)
            {
                if (prefixes.find(currXor ^ p) != prefixes.end())
                {
                    maxXor = currXor;
                    break;
                }
            }
        }

        return maxXor;
    }
};

// Runtime: 522 ms, faster than 43.98% of C++ online submissions for Maximum XOR of Two Numbers in an Array.
// Memory Usage: 74.4 MB, less than 45.99% of C++ online submissions for Maximum XOR of Two Numbers in an Array.
// time complexity: O(LN), L is length of largest number
// space complexity: O(N)
