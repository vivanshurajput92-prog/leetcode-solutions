/*
 * Problem: Check Divisibility by Digit Sum and Product
 * Problem ID: 3918
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 7.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-22
 */

class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1,add = 0;
        int temp = n;
        while(temp){
            int digit = temp % 10;
            add += digit;
            prod *= digit;
            temp /= 10;
        }
        return !(n % (prod + add));
    }
};