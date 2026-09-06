/*
 * Problem: Distinct Subsequences
 * Problem ID: 115
 * Difficulty: Hard
 * Language: C++
 * Runtime: 6 ms
 * Memory: 8.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-06
 */

class Solution {
public:
    int numDistinct(string &s, string &t){
        int n = s.length(),m = t.length();
        vector<unsigned int> dp(m+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1]) dp[j] += dp[j-1];
            }
        }
        return dp[m];
    }
};