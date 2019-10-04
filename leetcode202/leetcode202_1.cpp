class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        
        do {
            slow = next(slow);
            fast = next(fast);
            fast = next(fast);
            
            if (fast == 1 || slow == 1)
                return true;
        } while (slow != fast);
        
        return false;
    }
private:
    int next (int n) {
        int output = 0;
        while (n != 0) {
            int t = n % 10;
            output += t * t;
            n /= 10;
        }
        
        return output;
    }
};

// Runtime: 4 ms, faster than 66.31% of C++ online submissions for Happy Number.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Happy Number.
// time complexity: O(n)
// space complexity: O(1)