/*
 * Problem: Product of the Last K Numbers
 * Problem ID: 1477
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1079 ms
 * Memory: 111 MB
 * Synced From: LeetCode
 * Date: 2026-11-23
 */

class ProductOfNumbers {
public:
    vector<int> nums;
    ProductOfNumbers() {
        nums.resize(4*1e4+10,0);
    }

    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        for(int i=nums.size()-1;i>=nums.size()-k;i--){
            prod *= nums[i];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */