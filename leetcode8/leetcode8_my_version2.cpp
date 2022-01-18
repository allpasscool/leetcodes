class Solution
{
public:
    int myAtoi(string s)
    {
        int sign = 1;
        long long num = 0;
        bool signSet = false;
        bool seenDig = false;

        for (char &c : s)
        {
            if (c == '-')
            {
                if (signSet || seenDig)
                    break;
                sign = -1;
                signSet = true;
            }
            else if (c == '+')
            {
                if (signSet || seenDig)
                    break;
                sign = 1;
                signSet = true;
            }
            else if (c >= '0' && c <= '9')
            {
                num = num * 10 + c - '0';
                if (num * sign >= INT_MAX || num * sign <= INT_MIN)
                    break;

                seenDig = true;
            }
            else if (c == ' ' && (signSet || seenDig))
                break;
            else if (c != ' ')
                break;
        }

        if (num * sign > INT_MAX)
            return INT_MAX;
        if (num * sign < INT_MIN)
            return INT_MIN;

        return num * sign;
    }
};

// Runtime: 8 ms, faster than 22.27% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 7 MB, less than 89.48% of C++ online submissions for String to Integer (atoi).
// time complexity: O(n)
// space complexity: O(1)