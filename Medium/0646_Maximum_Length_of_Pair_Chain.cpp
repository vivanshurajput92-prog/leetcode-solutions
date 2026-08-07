/*
 * Problem: Maximum Length of Pair Chain
 * Problem ID: 646
 * Difficulty: Medium
 * Language: C++
 * Runtime: 313 ms
 * Memory: 163.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-07
 */

class Solution {
private:
    int f(int i,auto &pairs,int j,int n,auto &dp){
        if(i >= n) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];
        int pick = INT_MIN;
        if(j == -1) pick = 1 + f(i+1,pairs,i,n,dp);
        else if(pairs[j][1] < pairs[i][0]) pick = 1 + f(i+1,pairs,i,n,dp);
        int notPick = f(i+1,pairs,j,n,dp);
        return dp[i][j+1] = max(pick,notPick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        sort(pairs.begin(),pairs.end());
        return f(0,pairs,-1,n,dp);
    }
};