/*
 * Problem: Smallest Divisible Digit Product I
 * Problem ID: 3626
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-06
 */

class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+100;i++){
            long long prod = 1;
            int num = i;
            while(num){
                prod *= (num % 10);
                num /= 10;
            }
            if(prod % t == 0) return i;
        }
        return -1;
    }
};