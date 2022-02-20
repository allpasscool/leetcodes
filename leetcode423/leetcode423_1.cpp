class Solution
{
public:
    string originalDigits(string s)
    {
        // building hashmap letter -> its frequency
        unordered_map<char, int> count;
        for (char letter : s)
        {
            count[letter]++;
        }

        // building hashmap digit -> its frequency
        int out[10] = {0};
        // letter "z" is present only in "zero"
        out[0] = count['z'];
        // letter "w" is present only in "two"
        out[2] = count['w'];
        // letter "u" is present only in "four"
        out[4] = count['u'];
        // letter "x" is present only in "six"
        out[6] = count['x'];
        // letter "g" is present only in "eight"
        out[8] = count['g'];
        // letter "h" is present only in "three" and "eight"
        out[3] = count['h'] - out[8];
        // letter "f" is present only in "five" and "four"
        out[5] = count['f'] - out[4];
        // letter "s" is present only in "seven" and "six"
        out[7] = count['s'] - out[6];
        // letter "i" is present in "nine", "five", "six", and "eight"
        out[9] = count['i'] - out[5] - out[6] - out[8];
        // letter "n" is present in "one", "nine", and "seven"
        out[1] = count['n'] - out[7] - 2 * out[9];

        // building output string
        string output = "";
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < out[i]; j++)
                output += to_string(i);
        return output;
    }
};

// Runtime: 30 ms, faster than 45.41% of C++ online submissions for Reconstruct Original Digits from English.
// Memory Usage: 8.9 MB, less than 86.06% of C++ online submissions for Reconstruct Original Digits from English.
// time complexity: O(n)
// space complexity: O(1)