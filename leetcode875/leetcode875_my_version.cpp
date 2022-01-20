class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int minK = 1, maxK = 1;
        int ans = INT_MAX;

        for (int pile : piles)
        {
            maxK = max(maxK, pile);
        }
        maxK++;

        while (minK < maxK)
        {
            int mid = minK + (maxK - minK) / 2;
            int time = 0;

            for (int pile : piles)
            {
                time += pile / mid;
                // need one more hour
                if (pile % mid != 0)
                    time++;
            }

            // k is too small
            if (time > h)
                minK = mid + 1;
            else if (time <= h)
            {
                maxK = mid;
                ans = min(ans, mid);
            }
        }

        return ans;
    }
};

// Runtime: 32 ms, faster than 98.47% of C++ online submissions for Koko Eating Bananas.
// Memory Usage: 18.8 MB, less than 85.48% of C++ online submissions for Koko Eating Bananas.
// time complexity: O(n log m), m is the max number
// space complexity: O(1)