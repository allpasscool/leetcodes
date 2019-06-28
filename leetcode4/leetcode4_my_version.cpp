class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int median_loc = len / 2;
        std::vector<int>::iterator it1 = nums1.begin();
        std::vector<int>::iterator it2 = nums2.begin();
        double median;
        int next;
        
        for(int i = 0; i < len; i++){
            if(len % 2 == 0){
                if(it2 == nums2.end() || (it1 != nums1.end() && *it1 <= *it2)){
                    next = *it1;
                    it1++;
                }
                else{
                    next = *it2;
                    it2++;
                }
                
                if(i == (median_loc-1)){
                    median = (double) next;
                }
                else if(i == median_loc){
                    median += (double) next;
                    median /= 2;
                    break;
                }
            }
            else{
                if(it2 == nums2.end() || (it1 != nums1.end() && *it1 <= *it2)){
                    next = *it1;
                    it1++;
                }
                else{
                    next = *it2;
                    it2++;
                }
                
                if(i == median_loc){
                    median = (double) next;
                }
            }
        }
        
        return median;
    }
};
// Runtime: 12 ms, faster than 99.20% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 9.5 MB, less than 79.76% of C++ online submissions for Median of Two Sorted Arrays.
// O(n)