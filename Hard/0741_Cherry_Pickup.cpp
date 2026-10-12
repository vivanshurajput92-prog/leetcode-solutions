/*
 * Problem: Cherry Pickup
 * Problem ID: 741
 * Difficulty: Hard
 * Language: C++
 * Runtime: 56 ms
 * Memory: 36.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-12
 */

class Solution {
private:
    int f(int r1,int r2,int k,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int c1 = k - r1;
        int c2 = k - r2;
        if(c1 >= n || c2 >= n || r1 >= n || r2 >= n) return -1e9;
        if(dp[r1][r2][k] != INT_MIN) return dp[r1][r2][k];
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return dp[r1][r2][k] = -1e9;
        if(r1 == n-1 && r2 == n-1 && k == 2*n-2) return dp[r1][r2][k] = grid[n-1][n-1];
        int cherries = (r1 == r2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];
        return dp[r1][r2][k] = cherries + max({f(r1+1,r2+1,k+1,grid,dp),f(r1,r2+1,k+1,grid,dp),f(r1,r2,k+1,grid,dp),f(r1+1,r2,k+1,grid,dp)});
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2*n-1,INT_MIN)));
        return max(0,f(0,0,0,grid,dp));
    }
};