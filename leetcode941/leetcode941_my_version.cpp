class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        if (n < 3)
            return false;

        return findMountain(arr, 0);
    }

    bool findMountain(vector<int> &arr, int start)
    {
        int n = arr.size();
        bool up = false, down = false;

        if (n - start < 3)
            return false;

        // find increase
        while (start + 1 < n && arr[start] < arr[start + 1])
        {
            up = true;
            start++;
        }

        // end
        if (start + 1 == n || !up)
            return false;
        // equal
        else if (arr[start + 1] == arr[start])
            return false;

        // must decrease
        while (start + 1 < n && arr[start] > arr[start + 1])
        {
            start++;
        }

        // leave before end
        if (start + 1 != n)
            return false;

        return true;
    }
};

// Runtime: 38 ms, faster than 39.87% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 22.4 MB, less than 48.39% of C++ online submissions for Valid Mountain Array.
// time complexity: O(n)
// space complexity: o(1)