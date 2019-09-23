class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count, start;
        int degree = 0;
        int smallest_len = n;
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            ++count[num];
            
            if (start[num] == 0 && num != nums[0]) {
                start[num] = i;
            }
            
            if (count[num] > degree) {
                degree = count[num];
                smallest_len = i - start[num] + 1;
            }
            else if (count[num] == degree && (i - start[num] + 1) < smallest_len) {
                smallest_len = i - start[num] + 1;
            }
        }
        
        return smallest_len;
    }
};

// Runtime: 40 ms, faster than 81.70% of C++ online submissions for Degree of an Array.
// Memory Usage: 13 MB, less than 100.00% of C++ online submissions for Degree of an Array.
// time complexity: O(n)
// space complexity: O(n)