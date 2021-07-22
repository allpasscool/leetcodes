class RandomizedSet {
    Set<Integer> set;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        set = new HashSet<Integer>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (set.contains(val))
            return false;
        
        set.add(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!set.contains(val))
            return false;
        
        set.remove(val);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int randNum = rand.nextInt(set.size());
        return set.toArray(new Integer[set.size()])[randNum];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

// Runtime: 275 ms, faster than 5.03% of Java online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 85.1 MB, less than 55.19% of Java online submissions for Insert Delete GetRandom O(1).
// time complexity: insert O(1) remove O(1) getRandom O(n)
// space complexity: O(n)