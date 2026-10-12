/*
 * Problem: Cherry Pickup II
 * Problem ID: 1559
 * Difficulty: Hard
 * Language: C++
 * Runtime: 82 ms
 * Memory: 21.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-12
 */

class Solution {
private:
    int f(int c1,int c2,int r,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(c1 < 0 || c2 < 0 || c1 >= m || c2 >= m) return -1e9;
        if(dp[c1][c2][r] != INT_MIN) return dp[c1][c2][r];
        if(r == n-1) return dp[c1][c2][r] = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        int cherries = (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[c1][c2][r] = cherries + max({f(c1+1,c2,r+1,grid,dp),f(c1+1,c2+1,r+1,grid,dp),f(c1+1,c2-1,r+1,grid,dp),f(c1,c2,r+1,grid,dp),f(c1,c2+1,r+1,grid,dp),f(c1,c2-1,r+1,grid,dp),f(c1-1,c2,r+1,grid,dp),f(c1-1,c2+1,r+1,grid,dp),f(c1-1,c2-1,r+1,grid,dp)});
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(m,vector<int>(n,INT_MIN)));
        return max(0,f(0,m-1,0,grid,dp));
    }
};