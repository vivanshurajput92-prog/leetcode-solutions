/*
 * Problem: Reshape the Matrix
 * Problem ID: 566
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 15.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-05
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c) return mat;
        vector<vector<int>> ans(r,vector<int> (c));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[(i*n + j)/c][(i*n + j) % c] = mat[i][j];
            }
        }
        return ans;
    }
};