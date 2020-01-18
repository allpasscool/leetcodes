class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++hashmap[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (value % 2 == 0 
            && hashmap.find(value / 2) != hashmap.end()
            && hashmap[value / 2] >= 2) {
            return true;
        }
        
        for (auto& p : hashmap) {
            if ((p.first != value - p.first)
               && (hashmap.find(value - p.first) != hashmap.end())) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    unordered_map<int, int> hashmap; // hashmap[value] = size
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */


// Runtime: 140 ms, faster than 55.64% of C++ online submissions for Two Sum III - Data structure design.
// Memory Usage: 23.8 MB, less than 71.43% of C++ online submissions for Two Sum III - Data structure design.
// time complexity: add O(1) find O(n)
// space complexity: O(n)