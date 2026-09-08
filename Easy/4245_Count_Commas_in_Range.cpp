/*
 * Problem: Count Commas in Range
 * Problem ID: 4245
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.5 MB
 * Synced From: LeetCode
 * Date: 2026-09-08
 */

class Solution {
public:
    int countCommas(int n) {
        return (n-1000+1) > 0 ? (n-1000+1) : 0;
    }
};