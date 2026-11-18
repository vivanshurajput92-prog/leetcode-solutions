/*
 * Problem: Minimum Number of Changes to Make Binary String Beautiful
 * Problem ID: 3174
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 13.7 MB
 * Synced From: LeetCode
 * Date: 2026-11-18
 */

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i+=2){
            if(s[i] != s[i+1]) ans++;
        }
        return ans;
    }
};