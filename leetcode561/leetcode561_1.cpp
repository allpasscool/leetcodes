class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int arr[20001] = {0};
        int lim = 10000;
        
        for (int num: nums) {
            arr[num + lim]++;
        }
        
        int d = 0, sum = 0;
        
        for (int i = -10000; i <= 10000; i++) {
            sum += (arr[i + lim] + 1 - d) / 2 * i;
            d = (2 + arr[i + lim] - d) % 2;
        }
        
        return sum;
    }
};
// Runtime: 60 ms, faster than 96.09% of C++ online submissions for Array Partition I.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Array Partition I.
// time complexity: O(n) The whole hashmap arrarr of size nn is traversed only once.
// space complexity: O(n) A hashmap arrarr of size nn is used.