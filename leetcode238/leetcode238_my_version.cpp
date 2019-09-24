class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int production = 1;
        bool has_zero = false;
        bool more_than_one_zero = false;
        
        for(int& n: nums) {
            // have zero
            if (n == 0) {
                // have more than one zero
                if (has_zero) {
                    more_than_one_zero = true;
                    break;
                }
                
                has_zero = true;
                continue;
            }
            production *= n;
        }
            
        vector<int> output(nums.size(), 0);
        
        // more than one zero, all output is 0
        if (more_than_one_zero) {
            output = vector<int> (nums.size(), 0);
            return output;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int& n = nums[i];
            
            // only one zero && n == 0
            if (n == 0 && !more_than_one_zero)
                // output.push_back(production);
                output[i] = production;
            
            // // more than one zero
            // else if (more_than_one_zero)
            //     output.push_back(0);
            
            // only one zero && n != 0
            // since it is initialized to 0
            // we don't need to handle it
            else if (has_zero && n != 0)
                // output.push_back(0);
                // output[i] = 0;
                continue;
            
            // no zero
            else
                // output.push_back(production / n);
                output[i] = production / n;
        }
            
        return output;
    }
};

// Runtime: 36 ms, faster than 97.88% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 12.5 MB, less than 77.27% of C++ online submissions for Product of Array Except Self.
// time complexity: O(n)
// space complexity: O(1)