/*
 * Problem: Word Search
 * Problem ID: 79
 * Difficulty: Medium
 * Language: C++
 * Runtime: 270 ms
 * Memory: 10.8 MB
 * Synced From: LeetCode
 * Date: 2026-10-07
 */

class Solution {
    vector<int> dr = {0,0,-1,1};
    vector<int> dc = {-1,1,0,0};
private:
    int f(int i,int j,int pos,string &word,vector<vector<char>> &board,vector<vector<int>> &vis){
        if(pos == word.size()){
            return true;
        }
        for(int k=0;k<4;k++){
            int row = i + dr[k];
            int col = j + dc[k];
            if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == word[pos] && vis[row][col] == 0){
                vis[row][col] = 1;
                if(f(row,col,pos+1,word,board,vis)) return true;
                vis[row][col] = 0;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(f(i,j,1,word,board,vis)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};