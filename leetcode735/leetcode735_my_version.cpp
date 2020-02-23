class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> right;
        vector<int> ans;
        
        for (auto asteroid : asteroids) {
            // moving left and won't collide anything
            if (asteroid < 0 && right.empty()) {
                ans.push_back(asteroid);
                continue;
            }
            else {
                // moving right or stay
                if (asteroid >= 0) {
                    right.push(asteroid);
                }
                // moving left
                else {
                    // collide until this one explode or won't collide
                    while (!right.empty() 
                           && right.top() < abs(asteroid)) {
                        right.pop();
                    }
                    
                    // this one and the other one will explode together
                    if (!right.empty()
                       && right.top() == abs(asteroid)) {
                        right.pop();
                    }
                    // this one won't explode
                    else if (right.empty()) {
                        ans.push_back(asteroid);
                    }
                    // only this one explode
                }
            }
        }
        
        int ans_size = ans.size();
        while (!right.empty()) {
            ans.insert(begin(ans) + ans_size, right.top());
            right.pop();
        }
        
        return ans;
    }
};

// Runtime: 16 ms, faster than 79.75% of C++ online submissions for Asteroid Collision.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Asteroid Collision.
// time complexity: O(n)
// space complexity: O(n)