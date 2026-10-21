/*
 * Problem: Minimum Operations to Sort a String
 * Problem ID: 4220
 * Difficulty: Medium
 * Language: C++
 * Runtime: 21 ms
 * Memory: 27.6 MB
 * Synced From: LeetCode
 * Date: 2026-10-21
 */

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        char mx = 'a';
        char mn = 'z';
        bool inc = true;
        for(int i=0;i<n-1;i++){
            if(s[i+1] < s[i]){
                inc = false;
                break;
            }
        }
        if(inc) return 0;
        if(n == 2) return -1;
        for(int i=0;i<n;i++){
            if(s[i] < mn) mn = s[i];
            if(s[i] > mx) mx = s[i];
        }
        int ct_mn = 0,ct_mx = 0;
        for(int i=0;i<n;i++){
            if(s[i] == mn) ct_mn++;
            if(s[i] == mx) ct_mx++;
        }
        if(s[0] == mn || s[n-1] == mx) return 1;
        else if(s[n-1] == mn && s[0] == mx && ct_mx == 1 && ct_mn == 1) return 3;
        else return 2;
    }
};