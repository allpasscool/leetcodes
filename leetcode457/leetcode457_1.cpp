class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        
        int n = nums.size();
        
        // start point
        for (int i = 0; i < n; ++i) {
            // cout << "start point: " << i << endl; 
            if (nums[i] == 0)
                continue;
            
            int slow = i;
            int fast = advance(nums, i);
            
            // keep same direction, which is nums[i] * nums[fast] > 0
            while (nums[i] * nums[fast] > 0
                  && nums[i] * nums[advance(nums, fast)] > 0) {
                if (slow == fast) {
                    // this means the circle len is one
                    if (slow == advance(nums, fast))
                        break;
                    
                    return true;
                }
                
                slow = advance(nums, slow);
                fast = advance(nums, fast);
                fast = advance(nums, fast);
            }
            
            // don't find a circle, replace all visited to 0
            slow = i;
            int dir = nums[i];
            // same direction
            while (nums[slow] * dir > 0) {
                int next = advance(nums, slow);
                nums[slow] = 0;
                slow = next;
            }
        }
        
        return false;
    }
private:
    // move one step
    int advance(vector<int>& nums, int i) {
        int n = nums.size();
        i += nums[i] % n;
        
        if (i < 0)
            i += n;
        else if (i >= n)
            i %= n;
        
        return i;
    }
};


// Runtime: 4 ms, faster than 77.28% of C++ online submissions for Circular Array Loop.
// Memory Usage: 8.4 MB, less than 90.00% of C++ online submissions for Circular Array Loop.
// time complexity: O(n)
space complexity: O(1)

// public class Solution {
//     int len;
//     /**
//      * Moves the pointer 'i' ahead one iteration.
//      */
//     private int advance(int[] nums, int i) {
//         i += nums[i];
//         if (i < 0) i += len;
//         else if (i > len - 1) i %= len;
//         return i;
//     }
    
//     public boolean circularArrayLoop(int[] nums) {
//         // Handle bad input
//         if (nums == null || nums.length < 2) return false;
        
//         len = nums.length;
        
//         /**
//          * Check every possible start location.
//          * We may start at a short-loop, for instance, but the Array
//          * may still contain a valid loop.
//          */
//         for (int i = 0; i < len; i++) {
//             /**
//              * We set elements to 0 which are on known non-loop paths.
//              * So, if we encounter a 0, we know we're not on a loop path.
//              * So, move to the next start location in the list.
//              */
//             if (nums[i] == 0) continue;
            
//             // Stagger our starts, so we don't conclude we've found a loop,
//             // as we might otherwise when slow == fast.
//             int slow = i, fast = advance(nums, slow);
            
//             /** 
//              * Whether i is positive or negative defines our direction, so if
//              * the directions differ, so too will the signs.
//              * If the signs differ, we can't be in a 'forward' or a 'backward'
//              * loop, so we exit the traverse.
//              */
//             while (nums[i] * nums[fast] > 0 &&
//                     nums[i] * nums[advance(nums, fast)] > 0) {
//                 if (slow == fast) {
//                     if (slow == advance(nums, slow)) break; // 1-element loop
//                     return true;
//                 }
//                 slow = advance(nums, slow);
//                 fast = advance(nums, advance(nums, fast));
//             }
            
//             /**
//              * If we're here, we didn't find a loop, so we know this path
//              * doesn't have a loop, so we re-traverse it until we reverse
//              * direction or encounter a '0' element.
//              * During the re-traverse, we set each element we see to 0.
//              */
//             slow = i;
//             int sgn = nums[i];
//             while (sgn * nums[slow] > 0) {
//                 int tmp = advance(nums, slow);
//                 nums[slow] = 0;
//                 slow = tmp;
//             }
//         }
        
//         // We've tested the whole array and have not found a loop,
//         // therefore there isn't one, so return false.
//         return false;
//     }
// }
