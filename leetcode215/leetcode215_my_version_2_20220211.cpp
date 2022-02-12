class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int ans;
        int n = nums.size();
        int left = 0, right = n - 1;

        do
        {
            ans = partition(nums, left, right);

            if (ans < n - k)
            {
                left = ans + 1;
            }
            else if (ans > n - k)
            {
                right = ans - 1;
            }

        } while (ans != n - k);

        return nums[n - k];
    }

private:
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[right];
        int cur = left;

        for (int i = left; i < right; i++)
        {
            if (nums[i] <= pivot)
            {
                swap(nums[i], nums[cur]);
                cur++;
            }
        }

        swap(nums[cur], nums[right]);

        return cur;
    }
};

// Runtime: 163 ms, faster than 7.97% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 9.9 MB, less than 85.08% of C++ online submissions for Kth Largest Element in an Array.
// time complexity: O(n) in average O(n^2) worst case
// space complexity: O(1)