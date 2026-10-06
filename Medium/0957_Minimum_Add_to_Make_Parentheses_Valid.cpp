/*
 * Problem: Minimum Add to Make Parentheses Valid
 * Problem ID: 957
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-06
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int ans = 0;
        int openCount = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') openCount++;
            else openCount--;
            if(openCount < 0){
                ans++;
                openCount = 0;
            }
        }
        ans += openCount;
        return ans;
    }
};