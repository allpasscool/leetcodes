class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int curPoints = 0;

        // pick left k cards
        for (int i = 0; i < k; i++)
        {
            curPoints += cardPoints[i];
        }

        int left = k - 1, right = cardPoints.size() - 1;
        int maxPoint = curPoints;

        for (int i = 0; i < k; i++)
        {
            curPoints -= cardPoints[left];
            curPoints += cardPoints[right];
            left--;
            right--;

            maxPoint = max(maxPoint, curPoints);
        }

        return maxPoint;
    }
};

// Runtime: 56 ms, faster than 65.63% of C++ online submissions for Maximum Points You Can Obtain from Cards.
// Memory Usage: 42.4 MB, less than 46.21% of C++ online submissions for Maximum Points You Can Obtain from Cards.
// time complexity: O(n)
// space complexity: O(1)