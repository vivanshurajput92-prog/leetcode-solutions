/*
 * Problem: Decode Ways
 * Problem ID: 91
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-06
 */

class Solution {
private:
    int f(int i,string &s,vector<int> &dp){
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ways = f(i+1,s,dp);
        if(i+1 < s.length()){
            int val = (s[i] - '0') * 10 + (s[i+1] - '0'); 
            if(val <= 26 && val >= 1) ways += f(i+2,s,dp);
        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0') return 0;
        for(int i=1;i<n;i++){
            if(s[i] == '0' && s[i-1] > '2') return 0;
        }
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }
};