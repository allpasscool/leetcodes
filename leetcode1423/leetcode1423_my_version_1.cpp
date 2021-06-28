class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int left = 0, right = cardPoints.size() - 1;

        int maxPoint = findMaxScore(cardPoints, left, right, k);

        return maxPoint;
    }

private:
    int findMaxScore(vector<int> &cardPoints, int left, int right, int remain)
    {
        if (remain == 0)
        {
            return 0;
        }

        int pickLeft = cardPoints[left] + findMaxScore(cardPoints, left + 1, right, remain - 1);
        int pickRight = cardPoints[right] + findMaxScore(cardPoints, left, right - 1, remain - 1);

        return max(pickLeft, pickRight);
    }
};

// Time Limit Exceeded
// time complexity: O(2^k)
// space complexity: O(k)