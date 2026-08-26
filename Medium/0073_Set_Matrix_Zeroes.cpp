/*
 * Problem: Set Matrix Zeroes
 * Problem ID: 73
 * Difficulty: Medium
 * Language: C++
 * Runtime: N/A
 * Memory: N/A
 * Synced From: LeetCode
 * Date: 2026-08-26
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> copy = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> s_i,s_j;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    s_i.insert(i);
                    s_j.insert(j);
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s_i.find(i) == s_i.end() && s_j.find(j) == s_j.end()){
                    matrix[i][j] = copy[i][j];
                } 
            }
        }
    }
};