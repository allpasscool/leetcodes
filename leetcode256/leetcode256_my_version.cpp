class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> colors_costs(costs.size(), vector<int>(3)); // [r, b, g]
        
        if (costs.size() < 1) {
            return 0;
        }
        else {
            colors_costs[0][0] = costs[0][0];
            colors_costs[0][1] = costs[0][1];
            colors_costs[0][2] = costs[0][2];
            
            for (int i = 1; i < costs.size(); ++i) {
                colors_costs[i][0] = min(colors_costs[i - 1][1], colors_costs[i - 1][2]) 
                                        + costs[i][0];
                colors_costs[i][1] = min(colors_costs[i - 1][0], colors_costs[i - 1][2]) 
                                        + costs[i][1];
                colors_costs[i][2] = min(colors_costs[i - 1][0], colors_costs[i - 1][1]) 
                                        + costs[i][2];
            }
        }
        
        return min(colors_costs[costs.size() - 1][0], 
                   min(colors_costs[costs.size() - 1][1], colors_costs[costs.size() - 1][2]));
    }
};

// Runtime: 8 ms, faster than 76.39% of C++ online submissions for Paint House.
// Memory Usage: 10.1 MB, less than 42.86% of C++ online submissions for Paint House.
// time complexity: O(n)
// space complexity: O(n)