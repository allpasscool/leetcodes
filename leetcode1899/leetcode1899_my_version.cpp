class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int x = 0, y = 0, z = 0;

        for (vector<int> &t : triplets)
        {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2])
            {
                x = max(x, t[0]);
                y = max(y, t[1]);
                z = max(z, t[2]);
            }
        }

        return x == target[0] && y == target[1] && z == target[2];
    }
};
// Runtime: 448 ms, faster than 20.00% of C++ online submissions for Merge Triplets to Form Target Triplet.
// Memory Usage: 146.4 MB, less than 20.00% of C++ online submissions for Merge Triplets to Form Target Triplet.
// time complexity: O(n)
// space complexity: O(1)