/*
 * Problem: Reverse Degree of a String
 * Problem ID: 3811
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-20
 */

class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (i+1) * (26 - (s[i] - 'a'));
        }
        return ans;
    }
};