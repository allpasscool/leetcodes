class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> window;
        vector<double> ans;
        int n = nums.size();
        int i = 0;

        // push k items into window
        for (; i < k; i++)
            window.push_back(nums[i]);

        // sort window
        sort(begin(window), end(window));

        // do insertion sort and find median

        while (true)
        {
            // push median
            // odd
            if (k % 2 == 1)
            {
                ans.push_back(window[k / 2]);
            }
            else
            {
                ans.push_back(((double)window[k / 2] + window[k / 2 - 1]) / 2);
            }

            // end of nums?
            if (i >= n)
                break;

            // delete pop number
            deleteOldNum(window, nums[i - k]);

            // insert new num
            insertNewNum(window, nums[i]);

            i++;
        }

        return ans;
    }

private:
    void insertNewNum(vector<int> &window, int newNum)
    {
        int insertionPos = findPos(window, newNum);

        // add new num
        window.push_back(newNum);

        // move numbers
        rotateNumbers(window, insertionPos, true);
    }

    int findPos(vector<int> window, int newNum)
    {
        int left = 0, right = window.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (window[mid] < newNum)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    void rotateNumbers(vector<int> &window, int insertionPos, bool dir)
    {
        int n = window.size();

        // insert
        if (dir)
        {
            for (int i = n - 1; i > insertionPos; i--)
            {
                swap(window[i], window[i - 1]);
            }
        }
        // delete
        else
        {
            for (int i = insertionPos; i < n - 1; i++)
            {
                swap(window[i], window[i + 1]);
            }
        }
    }

    void deleteOldNum(vector<int> &window, int oldNum)
    {
        int deletePos = findPos(window, oldNum);

        // move numbers
        rotateNumbers(window, deletePos, false);

        window.pop_back();
    }
};

// Runtime: 585 ms, faster than 5.63% of C++ online submissions for Sliding Window Median.
// Memory Usage: 485.9 MB, less than 5.22% of C++ online submissions for Sliding Window Median.
// time complexity: O(n * k)
// space complexity: O(k)
// https://zxi.mytechroad.com/blog/difficulty/hard/leetcode-480-sliding-window-median/

// // Author: Huahua
// // Running time: 47 ms (<98.96%)
// class Solution {
//   public double[] medianSlidingWindow(int[] nums, int k) {
//     if (k == 0) return new double[0];
//     double[] ans = new double[nums.length - k + 1];
//     int[] window = new int[k];
//     for (int i = 0; i < k; ++i)
//       window[i] = nums[i];
//     Arrays.sort(window);
//     for (int i = k; i <= nums.length; ++i) {
//       ans[i - k] = ((double)window[k / 2] + window[(k - 1)/2]) / 2;
//       if (i == nums.length) break;
//       remove(window, nums[i - k]);
//       insert(window, nums[i]);
//     }
//     return ans;
//   }

//   // Insert val into window, window[k - 1] is empty before inseration
//   private void insert(int[] window, int val) {
//     int i = Arrays.binarySearch(window, val);
//     if (i < 0) i = - i - 1;
//     int j = window.length - 1;
//     while (j > i) window[j] = window[--j];
//     window[j] = val;
//   }

//   // Remove val from window and shrink it.
//   private void remove(int[] window, int val) {
//     int i = Arrays.binarySearch(window, val);
//     while (i < window.length - 1) window[i] = window[++i];
//   }

// }