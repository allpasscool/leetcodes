class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_map<string, int> targets;
        int ans = 0;

        for (int i = 0; i < targetWords.size(); i++)
        {
            sort(targetWords[i].begin(), targetWords[i].end());
            targets[targetWords[i]]++;
        }

        for (int i = 0; i < startWords.size(); i++)
        {
            // add one char
            for (int j = 0; j < 26; j++)
            {
                char c = (char)('a' + j); // without this check will time limit exceeded
                if (count(startWords[i].begin(), startWords[i].end(), c))
                    continue;
                string newWord = startWords[i] + c;
                sort(begin(newWord), end(newWord));

                if (targets.find(newWord) != targets.end())
                {
                    ans += targets[newWord];
                    targets.erase(newWord);
                }
            }
        }

        return ans;
    }
};

// Runtime: 1656 ms, faster than 6.78% of C++ online submissions for Count Words Obtained After Adding a Letter.
// Memory Usage: 111.1 MB, less than 45.47% of C++ online submissions for Count Words Obtained After Adding a Letter.
// time complexity: O(t * m log m + s * n log n * 26),
// t is size of target words, s is size of start words,
// m is the max len of target word, n is the max len of start word
// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/discuss/1676845/Simple-C%2B%2B-Solution-oror-Two-approaches-oror-HashSet%2BSorting-and-HashSet%2BBitmasking-oror-O(n)