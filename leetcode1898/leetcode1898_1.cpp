class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = s.size(), m = p.size();
        int reSize = removable.size();
        unordered_set<int> used;

        int left = 0, right = reSize;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            // add used
            for (int i = left; i <= mid; i++)
            {
                used.insert(removable[i]);
            }

            if (checkValid(s, p, used))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;

                // remove
                for (int i = left; i <= mid; i++)
                {
                    used.erase(removable[i]);
                }
            }
        }

        return left;
    }

    bool checkValid(string &s, string &p, unordered_set<int> &used)
    {
        int p1 = 0, p2 = 0;
        int n = s.size(), m = p.size();

        while (p1 < n && p2 < m)
        {
            if (used.find(p1) == used.end() && s[p1] == p[p2])
            {
                p2++;
            }

            p1++;
        }

        return p2 == m;
    }
};

// Runtime: 636 ms, faster than 20.00% of C++ online submissions for Maximum Number of Removable Characters.
// Memory Usage: 110 MB, less than 20.00% of C++ online submissions for Maximum Number of Removable Characters.
// time complexity: O(n log n)
// space complexity: O(n)

// class Solution {
// public:
//     int maximumRemovals(string s, string p, vector<int>& removable) {
//         //This question took me 3 wrong attempts before I realized that binary search works the best.
//         // What do I binary search then? I find the number of elements I can remove!
//         // The left boundary represents the lower limit (0 at first) while the right boundary represents the upper limit (the length of the removable array)
//         // Each time, I find the middle number (which is an attempt to remove that number of letters from the string)
//         // I also use an array of characters and replace those letters removed with the '/' symbol (can choose anything as long as it's a non-letter)
//         // This should be faster and more convenient to work with as compared to removing letters directly from a string (high time complexity from string concatenation)

//         //Firstly, I express the letters into an array of characters
//         string CopyS = s;
//         //Set up my boundaries.
//         int l = 0, r = removable.size();
//         while (l <= r) {
//             //'mid' represents how many letters I remove this round.
//             int mid = l + (r - l) / 2;
//             //'Remove' those letters!
//             for (int i = 0; i < mid; i++)
//                 CopyS[removable[i]] = '/';

//             //I perform a simple check to see if p is still a subsequence of it. If it is, change the lower boundary.
//             if (check(CopyS,p))
//             {
//                 l = mid + 1;
//             }
//             //Otherwise, I replace back all the CopyS that I had removed.
//             //Then, I change the upper boundary.
//             else {
//                 for (int i = 0;i < mid; i++)
//                     CopyS[removable[i]] = s[removable[i]];
//                 r = mid - 1;
//             }
//         }
//         return r;
//     }

//     //This is a standard procedure for checking if p is a subsequence of the array of characters.
//     //I use two-pointers to keep track of which char I'm looking at now in the char array, and another to keep track of which char I'm looking at in p.
//     // If the character wasn't 'removed' (remember this is indicated by the '/' symbol) and the characters are equal, I increment both pointers.
//     //Otherwise, I only increment the first pointer pointing to the array of characters.
//     bool check(string& letters, string p) {
//         int i1 = 0, i2 = 0;

//         while (i1 < letters.size() && i2 < p.size()) {
//             char curr = letters[i1], curr2 = p[i2];

//             if (curr != '/' && curr == curr2)
//                 i2++;

//             i1++;
//         }

//         //If i2 == p.length(), it means that I had managed to match all of the characters in String p!
//         if (i2 == p.length())
//             return true;

//         return false;
//     }
// };

// // https://leetcode.com/problems/maximum-number-of-removable-characters/discuss/1268477/JAVA-Binary-Search-with-Detailed-Explanation!