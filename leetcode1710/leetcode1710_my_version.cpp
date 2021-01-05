class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[1] > right[1];
        });
        
        int ans = 0;
        int count = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            if (count + boxTypes[i][0] <= truckSize) {
                ans += boxTypes[i][0] * boxTypes[i][1];
                count += boxTypes[i][0];
            }
            else {
                ans += (truckSize - count) * boxTypes[i][1];
                return ans;
            }
        }
        
        return ans;
    }
};

// time complexity: O(n log n)
// space complexity: O(1)
// Runtime: 80 ms, faster than 85.99% of C++ online submissions for Maximum Units on a Truck.
// Memory Usage: 16.5 MB, less than 66.27% of C++ online submissions for Maximum Units on a Truck.