/*
 * Problem: Count Islands With Total Value Divisible by K
 * Problem ID: 3823
 * Difficulty: Medium
 * Language: C++
 * Runtime: 192 ms
 * Memory: 207.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-26
 */

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 1 || grid[i][j] == 0) continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                long long sum = grid[i][j];
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nxt_row = dr[k] + row;
                        int nxt_col = dc[k] + col;
                        if(nxt_row >= 0 && nxt_col >= 0 && nxt_row < n && nxt_col < m && vis[nxt_row][nxt_col] == 0 && grid[nxt_row][nxt_col] != 0){
                            q.push({nxt_row,nxt_col});
                            vis[nxt_row][nxt_col] = 1;
                            sum += grid[nxt_row][nxt_col];
                        }
                    }
                }
                if(sum % k == 0) ans++;
            }
        }
        return ans;
    }
};