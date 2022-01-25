class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int cur = 0;

        // walk up
        while (cur + 1 < n && arr[cur] < arr[cur + 1])
            cur++;

        // peak can't be first or last
        if (cur == 0 || cur == n - 1)
            return false;

        // walk down
        while (cur + 1 < n && arr[cur] > arr[cur + 1])
            cur++;

        return cur == n - 1;
    }
};

// Runtime: 50 ms, faster than 22.11% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 22.5 MB, less than 48.39% of C++ online submissions for Valid Mountain Array.
// time complexity: O(n)
// space complexity: O(1)