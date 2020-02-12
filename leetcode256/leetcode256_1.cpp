class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> colors_costs(3); // [r, b, g]
        
        if (costs.size() < 1) {
            return 0;
        }
        else {
            colors_costs[0] = costs[0][0];
            colors_costs[1] = costs[0][1];
            colors_costs[2] = costs[0][2];

            vector<int> tmp(3);
            
            for (int i = 1; i < costs.size(); ++i) {
                tmp[0] = min(colors_costs[1], colors_costs[2]) 
                                        + costs[i][0];
                tmp[1] = min(colors_costs[0], colors_costs[2]) 
                                        + costs[i][1];
                tmp[2] = min(colors_costs[0], colors_costs[1]) 
                                        + costs[i][2];

                colors_costs = tmp;
            }
        }
        
        return min(colors_costs[0], 
                   min(colors_costs[1], colors_costs[2]));
    }
};


// Runtime: 8 ms, faster than 76.39% of C++ online submissions for Paint House.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Paint House.
// time complexity: O(n)
// space complexity: O(n)