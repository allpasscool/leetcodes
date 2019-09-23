class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        
        for (int i = 1; i * i <= n; ++i)
            ++count;
        
        return count;
    }
};
// Explanation:
// A light will be toggled only during the round of its factors, 
// e.g. number 6 light will be toggled at 1,2,3,6 and light 12 will be toggled at 1,2,3,4,6,12. 
// The final state of a light is on and off only depends on if the number of its factor is odd or even. 
// If odd, the light is on and if even the light is off. 
// The number of one number's factor is odd if and only if it is a perfect square!
// So we will only need to loop to find all the perfect squares that are smaller than n!


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Bulb Switcher.
// Memory Usage: 8.2 MB, less than 88.89% of C++ online submissions for Bulb Switcher.
// time complexity: O(log n)
// space complexity: O(1)