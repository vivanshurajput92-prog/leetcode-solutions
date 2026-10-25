/*
 * Problem: Number of Closed Islands
 * Problem ID: 1380
 * Difficulty: Medium
 * Language: C++
 * Runtime: 8 ms
 * Memory: 18.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-25
 */

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ct = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 1 || grid[i][j] == 1) continue;
                bool flag = false;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    if(row == 0 || row == n-1 || col == m-1 || col == 0) flag  = true;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nxt_row = row + dr[k];
                        int nxt_col = col + dc[k];
                        if(nxt_row >= 0 && nxt_col >= 0 && nxt_row < n && nxt_col < m && vis[nxt_row][nxt_col] == 0 && grid[nxt_row][nxt_col] == 0){
                            q.push({nxt_row,nxt_col});
                            vis[nxt_row][nxt_col] = 1;
                        }
                    }
                }
                if(!flag) ct++;
            }
        }
        return ct;
    }
};