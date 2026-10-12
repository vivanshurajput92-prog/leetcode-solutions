/*
 * Problem: Cherry Pickup II
 * Problem ID: 1559
 * Difficulty: Hard
 * Language: C++
 * Runtime: 41 ms
 * Memory: 13.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-12
 */

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m+2,vector<int>(m+2,-1e9)),curr(m+2,vector<int>(m+2,-1e9));
        for(int c1=1;c1<=m;c1++){
            for(int c2=1;c2<=m;c2++){
                dp[c1][c2] = (c1 == c2) ? grid[n-1][c1-1] : grid[n-1][c1-1] + grid[n-1][c2-1];
            }
        }
        for(int r=n-2;r>=0;r--){
            for(int c1=1;c1<=m;c1++){
                for(int c2=1;c2<=m;c2++){
                    int cherries = (c1 == c2) ? grid[r][c1-1] : grid[r][c1-1] + grid[r][c2-1];
                    curr[c1][c2] = cherries + max({dp[c1+1][c2],dp[c1+1][c2+1],dp[c1+1][c2-1],dp[c1][c2],dp[c1][c2+1],dp[c1][c2-1],dp[c1-1][c2],dp[c1-1][c2+1],dp[c1-1][c2-1]});
                }
            }
            swap(dp,curr);
        }
        return max(0,dp[1][m]);
    }
};