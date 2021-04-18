class Logger {
    private HashMap<String, Integer> hashmap;
    
    /** Initialize your data structure here. */
    public Logger() {
        hashmap = new HashMap<>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!hashmap.containsKey(message)) {
            hashmap.put(message, timestamp);
            return true;
        }
        else {
            int last_time = hashmap.get(message);
            
            if (timestamp - last_time >= 10) {
                hashmap.put(message, timestamp);
                return true;
            }
            else {
                return false;
            }
        }
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */

// Runtime: 26 ms, faster than 82.54% of Java online submissions for Logger Rate Limiter.
// Memory Usage: 46.9 MB, less than 58.96% of Java online submissions for Logger Rate Limiter.
// time complexity: O(1)
// space complexity: O(m) at most m unique different msg