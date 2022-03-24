class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        long long ans = 0;
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int hStart = 0, vStart = 0;
        long long maxV = 0, maxH = 0;

        for (int &hEnd : horizontalCuts)
        {
            maxH = max(maxH, (long long)(hEnd - hStart));
            hStart = hEnd;
        }

        for (int &vEnd : verticalCuts)
        {
            maxV = max(maxV, (long long)(vEnd - vStart));
            vStart = vEnd;
        }

        ans = maxH * maxV;

        return ans % (1000000007);
    }
};

// Runtime: 94 ms, faster than 54.48% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
// Memory Usage: 32.4 MB, less than 37.06% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
// time complexity :O(v log v + h log h)
// space complexity: O(1)