class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int ans = 0;
        int len = flowerbed.size();

        // special case [0]
        if (len == 1)
        {
            return flowerbed[0] == 0 ? 1 >= n : 0 >= n;
        }

        for (int i = 0; i < len; i++)
        {
            // is empty
            if (flowerbed[i] == 0)
            {
                // middle
                if (i > 0 && flowerbed[i - 1] == 0 && i + 1 < len && flowerbed[i + 1] == 0)
                {
                    ans++;
                    i++;
                }
                // head
                else if (i == 0 && i + 1 < len && flowerbed[i + 1] == 0)
                {
                    ans++;
                    i++;
                }
                // tail
                else if (i == len - 1 && flowerbed[i - 1] == 0)
                {
                    i++;
                    ans++;
                }
            }
        }

        return ans >= n;
    }
};

// Runtime: 20 ms, faster than 47.51% of C++ online submissions for Can Place Flowers.
// Memory Usage: 20.4 MB, less than 20.95% of C++ online submissions for Can Place Flowers.
// time complexity: O(n)
// space complexity: O(1)