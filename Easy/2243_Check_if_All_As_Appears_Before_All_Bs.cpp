/*
 * Problem: Check if All A's Appears Before All B's
 * Problem ID: 2243
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.2 MB
 * Synced From: LeetCode
 * Date: 2026-11-22
 */

class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool b_found = false;
        for(int i=0;i<n;i++){
            if(s[i] == 'b') b_found = true;
            if(s[i] == 'a' && b_found) return false;
        }
        return true;
    }
};