/*
 * Problem: Maximum Nesting Depth of the Parentheses
 * Problem ID: 1737
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.4 MB
 * Synced From: LeetCode
 * Date: 2026-09-28
 */

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ct = 0;
        int max = -1;
        for(int i=0;i<n;i++){
            if(ct > max) max = ct;
            if(s[i] == '(') ct++;
            else if(s[i] == ')') ct--;
            else continue;
        }
        return max;
    }
};