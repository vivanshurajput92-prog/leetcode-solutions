/*
 * Problem: Twisted Mirror Path Count
 * Problem ID: 3938
 * Difficulty: Medium
 * Language: C++
 * Runtime: 96 ms
 * Memory: 224.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-31
 */

class Solution {
    int M = 1e9 + 7;
private:
    int f(int i,int j,int last,vector<vector<int>> &grid,vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i][j] == 1){
            if(last == 0) return f(i+1,j,1,grid,dp);
            else if(last == 1) return f(i,j+1,0,grid,dp);
        }
        int right = f(i,j+1,0,grid,dp);
        int down = f(i+1,j,1,grid,dp);
        return dp[i][j] = (right+down) % M;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,-1,grid,dp);
    }
};