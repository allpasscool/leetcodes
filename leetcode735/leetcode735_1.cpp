class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        
        for (auto asteroid : asteroids) {
            // won't collide
            if (asteroid >= 0 || ans.empty() || ans.back() < 0) {
                ans.push_back(asteroid);
                continue;
            }
            
            while (!ans.empty() 
                  && ans.back() >= 0
                  && ans.back() < abs(asteroid)) {
                ans.pop_back();
            }
            
            // survive ?
            if (ans.empty() || ans.back() < 0) {
                ans.push_back(asteroid);
            }
            // expliode together
            else if  (!ans.empty() && ans.back() == abs(asteroid)) {
                ans.pop_back();
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/asteroid-collision/discuss/109694/JavaC%2B%2B-Clean-Code
// Runtime: 20 ms, faster than 37.77% of C++ online submissions for Asteroid Collision.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Asteroid Collision.
// time complexity: O(n)
// space complexity: O(n)