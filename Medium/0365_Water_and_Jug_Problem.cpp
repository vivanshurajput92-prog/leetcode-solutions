/*
 * Problem: Water and Jug Problem
 * Problem ID: 365
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 7.7 MB
 * Synced From: LeetCode
 * Date: 2026-11-13
 */

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        return target % __gcd(x,y) == 0;
    }
};