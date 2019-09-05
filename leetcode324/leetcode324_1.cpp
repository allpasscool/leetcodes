class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // average O(n)
        // There are a lot of claims on StackOverflow and elsewhere that nth_element is O(n)
        // and that it is typically implemented with Introselect.
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        
        // i used to locate numbers bigger than mid at odd index, from left to right
        // j used to locate numbers less than mid at even index, from right to left
        // in this way, the numbers equal to mid will be separated to two ends, we don't need to consider these numbers
        // p is current checked number's index
        int i = 1, j = n % 2 == 0 ? n - 2 : n - 1, p = 0;
        
        
        
        while (p < n) {
            // for (int t = 0; t < n; t++) {
            //     cout << nums[t] << ", ";
            // }
            // cout << endl;
            // if current number is bigger than mid, and p > i
            // (if p <= i, means that nums[p] alread has been located)
            // or p is even index.
            // Then nums[p] needs to be located at i.
            if (nums[p] > mid && (p > i || p % 2 == 0)) {
                // cout << "p, i: " << p << ", " << i << endl;
                swap(nums[p], nums[i]);
                i += 2; // locate a bigger number
            }
            else if (nums[p] < mid && (p < j || p % 2 == 1)) {
                // cout << "p, j: " << p << ", " << j << endl;
                swap(nums[p], nums[j]);
                j -= 2; //located a smaller number
            }
            else {
                // cout << "p++: " << p << endl;
                p++;    //if nums[p] is equal to mid, or has been located, jump it.
            }
        }
        //  worst O(2n), with locate every number and check every number
        
        return;
    }
};
// Runtime: 68 ms, faster than 89.76% of C++ online submissions for Wiggle Sort II.
// Memory Usage: 11.1 MB, less than 80.77% of C++ online submissions for Wiggle Sort II.
// time complextiy: O(n)
// space complexity: O(1)

//[4, 5, 5, 6]
// [4, 5, 5, 5, 5, 5, 3, 8, 7, 6]
// 5, 4, 3, 5, 5, 5, 6, 5, 7, 8, 
// p++: 0
// 5, 4, 3, 5, 5, 5, 6, 5, 7, 8, 
// p, j: 1, 8
// 5, 7, 3, 5, 5, 5, 6, 5, 4, 8, 
// p++: 1
// 5, 7, 3, 5, 5, 5, 6, 5, 4, 8, 
// p, j: 2, 6
// 5, 7, 6, 5, 5, 5, 3, 5, 4, 8, 
// p, i: 2, 1
// 5, 6, 7, 5, 5, 5, 3, 5, 4, 8, 
// p, i: 2, 3
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 2
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 3
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 4
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 5
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 6
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 7
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p++: 8
// 5, 6, 5, 7, 5, 5, 3, 5, 4, 8, 
// p, i: 9, 5
// 5, 6, 5, 7, 5, 8, 3, 5, 4, 5, 
// p++: 9
// [5,6,5,7,5,8,3,5,4,5]
// [4, 5, 5, 5, 5, 3, 7, 4, 8]
// 5, 4, 4, 3, 5, 5, 7, 5, 8, 
// p++: 0
// 5, 4, 4, 3, 5, 5, 7, 5, 8, 
// p, j: 1, 8
// 5, 8, 4, 3, 5, 5, 7, 5, 4, 
// p++: 1
// 5, 8, 4, 3, 5, 5, 7, 5, 4, 
// p, j: 2, 6
// 5, 8, 7, 3, 5, 5, 4, 5, 4, 
// p, i: 2, 1
// 5, 7, 8, 3, 5, 5, 4, 5, 4, 
// p, i: 2, 3
// 5, 7, 3, 8, 5, 5, 4, 5, 4, 
// p, j: 2, 4
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 2
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 3
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 4
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 5
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 6
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 7
// 5, 7, 5, 8, 3, 5, 4, 5, 4, 
// p++: 8
// [5,7,5,8,3,5,4,5,4]