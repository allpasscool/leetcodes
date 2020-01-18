class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        for (int i = 0; i < numbers.size(); ++i) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                return {left + 1, right + 1};
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
// Memory Usage: 9.6 MB, less than 37.25% of C++ online submissions for Two Sum II - Input array is sorted.
// time complexity: O(n)
// space complexity: O(1)