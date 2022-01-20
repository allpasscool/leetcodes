class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int l = 1, r = 1000000000;
        while (l < r)
        {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

// Runtime: 88 ms, faster than 15.82% of C++ online submissions for Koko Eating Bananas.
// Memory Usage: 18.7 MB, less than 99.39% of C++ online submissions for Koko Eating Bananas.
// time complexity: O(n⋅logm)
// space complexity: O(1)
// https://leetcode.com/problems/koko-eating-bananas/discuss/152324/JavaC%2B%2BPython-Binary-Search