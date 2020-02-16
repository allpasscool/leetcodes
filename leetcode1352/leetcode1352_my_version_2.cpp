class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
        if (productions.empty()) {
            productions.push_back(num);
        }
        else {
            productions.push_back(productions.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k == (int) productions.size()) {
            return productions.back();
        }
        else if (productions[productions.size() - k - 1] != 0) {
            return productions.back() / productions[productions.size() - k - 1];
        }
        else {
            int production = 1;
            int n = nums.size() - 1;

            for (int i = 0; i < k; ++i) {
                production *= nums[n - i];
                if (production == 0) {
                    return 0;
                }
            }
            return production;
        }
    }
private:
    vector<int> nums;
    vector<int> productions;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */


// Runtime: 184 ms, faster than 100.00% of C++ online submissions for Product of the Last K Numbers.
// Memory Usage: 63.7 MB, less than 100.00% of C++ online submissions for Product of the Last K Numbers.
// time complexity: O(n)
// space complexity: O(n)