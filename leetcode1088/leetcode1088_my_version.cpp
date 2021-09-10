class Solution {
public:
    int confusingNumberII(int n) {
        
        int ans = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (check(i) != i)
                ans++;
        }
        
        return ans;
    }
    
    int check(int num)
    {
        int original = num;
        int newNum = 0;
        while (num > 0)
        {
            int remainder = num % 10;
            if (remainder != 0 && remainder != 1 && remainder != 6 && remainder != 8 && remainder != 9)
                return original;
            
            newNum *= 10;
            
            if (remainder == 0)
                newNum += 0;
            else if (remainder == 1)
                newNum += 1;
            else if (remainder == 6)
                newNum += 9;
            else if (remainder == 8)
                newNum += 8;
            else if (remainder == 9)
                newNum += 6;
            
            num = num / 10;
        }
        
        return newNum;
    }
};

// time complexity: O(n * log n)
// space complexity: O(1)
// Time Limit Exceeded 1000000000
