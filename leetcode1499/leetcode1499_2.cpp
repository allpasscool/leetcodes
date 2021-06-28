// Author: Huahua
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        deque<pair<int, int>> q; // {y - x, x} Sort by y - x.
        int ans = INT_MIN;
        for (const auto &p : points)
        {
            const int xj = p[0];
            const int yj = p[1];
            // Remove invalid points, e.g. xj - xi > k
            while (!q.empty() && xj - q.front().second > k)
                q.pop_front();
            if (!q.empty())
                ans = max(ans, xj + yj + q.front().first);
            while (!q.empty() && yj - xj >= q.back().first)
                q.pop_back();
            q.emplace_back(yj - xj, xj);
        }
        return ans;
    }
};

// Runtime: 268 ms, faster than 68.19% of C++ online submissions for Max Value of Equation.
// Memory Usage: 91.1 MB, less than 77.86% of C++ online submissions for Max Value of Equation.
// time complexity: O(n)
// space complexity: O(n)
// https://www.youtube.com/watch?v=GahRKbpoQVQ&ab_channel=HuaHua
// https://zxi.mytechroad.com/blog/queue/leetcode-1499-max-value-of-equation/