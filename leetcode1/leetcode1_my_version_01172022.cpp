class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> complement;

        for (int i = 0; i < nums.size(); i++)
        {
            if (complement.find(target - nums[i]) != complement.end())
            {
                return {complement[target - nums[i]], i};
            }

            complement[nums[i]] = i;
        }

        return {0, 0};
    }
};

// Runtime: 18 ms, faster than 55.94% of C++ online submissions for Two Sum.
// Memory Usage: 10.8 MB, less than 45.40% of C++ online submissions for Two Sum.
// time complexity: O(n)
// space complexity: O(n)