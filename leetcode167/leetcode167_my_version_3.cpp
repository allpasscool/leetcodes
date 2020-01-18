class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto left = numbers.begin();
        auto right = numbers.end() - 1;
        
        while (left != right) {
            int sum = *left + *right;
            
            if (sum == target) {
                return {(int) (left - numbers.begin() + 1),
                       (int) (right - numbers.begin() + 1)};
            }
            else if (sum > target) {
                right--;
            }
            else {
                ++left;
            }
        }
        
        return {};
    }
};


// Runtime: 8 ms, faster than 56.55% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.6 MB, less than 39.22% of C++ online submissions for Two Sum II - Input array is sorted.
// time complexity: O(n)
// space complexity: O(1)