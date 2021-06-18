class Solution {

    static Map<Character, Integer> values = new HashMap<>();

    static {
        values.put('M', 1000);
        values.put('D', 500);
        values.put('C', 100);
        values.put('L', 50);
        values.put('X', 10);
        values.put('V', 5);
        values.put('I', 1);
    }

    public int romanToInt(String s) {

        int sum = 0;
        int i = 0;
        while (i < s.length()) {
            Character currentSymbol = s.charAt(i);
            int currentValue = values.get(currentSymbol);
            int nextValue = 0;
            if (i + 1 < s.length()) {
                Character nextSymbol = s.charAt(i + 1);
                nextValue = values.get(nextSymbol);
            }

            if (currentValue < nextValue) {
                sum += (nextValue - currentValue);
                i += 2;
            } else {
                sum += currentValue;
                i += 1;
            }

        }
        return sum;
    }
}

// Runtime: 4 ms, faster than 77.40% of Java online submissions for Roman to
// Integer.
// Memory Usage: 39 MB, less than 84.68% of Java online submissions for Roman to
// Integer.
// time complexity: O(n)
// space complexity: O(1)