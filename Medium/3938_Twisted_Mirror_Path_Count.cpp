/*
 * Problem: Twisted Mirror Path Count
 * Problem ID: 3938
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1307 ms
 * Memory: 468.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-31
 */

class Solution {
    int M = 1e9 + 7;
private:
    int f(int i,int j,int last,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;
        if(dp[i][j][last+1] != -1) return dp[i][j][last+1];
        if(grid[i][j] == 1){
            if(last == 0) return dp[i][j][last+1] = f(i+1,j,1,grid,dp);
            else if(last == 1) return dp[i][j][last+1] = f(i,j+1,0,grid,dp);
        }
        long long right = f(i,j+1,0,grid,dp);
        long long down = f(i+1,j,1,grid,dp);
        return dp[i][j][last+1] = (right+down) % M;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return f(0,0,-1,grid,dp);
    }
};