/*
 * Problem: Longest Increasing Path in a Matrix
 * Problem ID: 329
 * Difficulty: Hard
 * Language: C++
 * Runtime: 18 ms
 * Memory: 21 MB
 * Synced From: LeetCode
 * Date: 2026-10-06
 */

class Solution{
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,-1,1};
private:
    int f(int i,int j,vector<vector<int>> &matrix,int &n,int &m,vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        int possible = false;
        int mx = 0;
        for(int k=0;k<4;k++){
            int row = i + dr[k];
            int col = j + dc[k];
            if(row >= 0 && row < n && col >=0 && col < m && matrix[row][col] > matrix[i][j]){
                possible = true;
                mx = max(mx,1+f(row,col,matrix,n,m,dp));
            }
        }
        if(!possible) return dp[i][j] = 1;
        return dp[i][j] = mx;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,f(i,j,matrix,n,m,dp));
            }
        }
        return ans;
    }
};