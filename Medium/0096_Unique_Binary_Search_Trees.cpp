/*
 * Problem: Unique Binary Search Trees
 * Problem ID: 96
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-06
 */

class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) return n;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;dp[2] = 2;
        for(int i=3;i<=n;i++){
            for(int j=0;j<=i-1;j++){
                dp[i] += (dp[j] * dp[i-j-1]);
            }
        }
        return dp[n];
    }
};