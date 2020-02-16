class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int production = 1;
        int n = nums.size() - 1;
        
        for (int i = 0; i < k; ++i) {
            production *= nums[n - i];
        }
        
        return production;
    }
private:
    vector<int> nums;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


// Runtime: 1504 ms, faster than 9.09% of C++ online submissions for Product of the Last K Numbers.
// Memory Usage: 62.7 MB, less than 100.00% of C++ online submissions for Product of the Last K Numbers.
// time complexity: O(n * k)
// space complexity: O(n)