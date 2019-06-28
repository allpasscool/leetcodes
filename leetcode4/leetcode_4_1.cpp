class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_len = nums1.size();
        int nums2_len = nums2.size();
        
        if(nums1_len > nums2_len){  //to ensure nums1_len <= nums2_len
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int start = 0, end = nums1_len, half_len = (nums1_len + nums2_len + 1) / 2;
        
        while(start <= end){
            //num of nums1 elements in left side of median
            //binary search
            int nums1_left = (start + end) / 2;
            //num fo nums2 elements in left side of meidan
            int nums2_left = half_len - nums1_left;
            
            if(nums1_left < end && nums2[nums2_left - 1] > nums1[nums1_left]){
                start = nums1_left + 1; // nums1_left is too small
            }
            else if(nums1_left > start && nums1[nums1_left - 1] > nums2[nums2_left]){
                end = nums1_left - 1; //nums1_left is too big
            }
            else{//found answer
                //left side of median
                int max_left;
                
                if(nums1_left == 0){
                    max_left = nums2[nums2_left -1];
                }
                else if(nums2_left == 0){
                    max_left = nums1[nums1_left -1];
                }
                else{
                    max_left = std::max(nums1[nums1_left -1], nums2[nums2_left - 1]);
                }
                
                if( (nums1_len + nums2_len) % 2 == 1 ){
                    return max_left;
                }
                
                //right side of median
                int min_right;
                if(nums1_left == nums1_len){
                    min_right = nums2[nums2_left];
                }
                else if(nums2_left == nums2_len){
                    min_right = nums1[nums1_left];
                }
                else{
                    min_right = std::min(nums1[nums1_left], nums2[nums2_left]);
                }
                
                return (double)(max_left + min_right) / 2.0;
                
            }
        }
        
        //doesn't find an answer, error
        return 0.0;
    }
};
// Runtime: 20 ms, faster than 83.84% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 9.7 MB, less than 58.08% of C++ online submissions for Median of Two Sorted Arrays.
// Time complexity: O(log(min(m,n)).
// At first, the searching range is [[0,m]. And the length of this searching range will be reduced by half after each loop. So, we only need \log(m)log(m) loops. Since we do constant operations in each loop, so the time complexity is O\big(\log(m)\big)O(log(m)). Since m \leq nm≤n, so the time complexity is O(log(min(m,n))).
// Space complexity: O(1).
// We only need constant memory to store 99 local variables, so the space complexity is O(1).