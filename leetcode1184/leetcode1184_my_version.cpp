class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int clockwise = 0, counter_clockwise = 0;
        
        if (n <= 1) {
            return 0;
        }
        else if (n == 2) {
            return min(distance[0], distance[1]);
        }
        
        for (int i = start; (i % n) != destination; i++) {
            i = i % n;
            
            clockwise += distance[i];
        }
        
        for (int i = start - 1; (i % n) + 1 != destination; i--) {
            if (i < 0) {
                i = n - 1;
            }
            
            counter_clockwise += distance[i];
        }
        
        return min(clockwise, counter_clockwise);
    }
};
// Runtime: 4 ms, faster than 96.01% of C++ online submissions for Distance Between Bus Stops.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Distance Between Bus Stops.
// time complexity: O(n)
// space copmleixty: O(1)