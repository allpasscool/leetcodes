// Author: Huahua
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> q; // {y - x, x}
        q.emplace(0, -1e9);
        int ans = INT_MIN;

        for (const auto &p : points)
        {
            const int x = p[0], y = p[1];
            while (!q.empty() && x - q.top().second > k)
                q.pop();

            if (!q.empty())
                ans = max(ans, x + y + q.top().first);

            q.emplace(y - x, x);
        }

        return ans;
    }
};

// Runtime: 252 ms, faster than 92.88% of C++ online submissions for Max Value of Equation.
// Memory Usage: 92.2 MB, less than 63.27% of C++ online submissions for Max Value of Equation.
// time complexity: O(n log n)
// space complexity: O(n)
// https://www.youtube.com/watch?v=GahRKbpoQVQ&ab_channel=HuaHua
// https://zxi.mytechroad.com/blog/queue/leetcode-1499-max-value-of-equation/