/*
 * Problem: Create Grid With Exactly One Path
 * Problem ID: 4342
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 11 MB
 * Synced From: LeetCode
 * Date: 2026-10-27
 */

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m);
        for(int i=0;i<m;i++){
            string s = "";
            for(int j=0;j<n;j++) s += '#';
            res[i] = s;
        }
        for(int j=0;j<n;j++) res[0][j] = '.';
        for(int i=0;i<m;i++) res[i][n-1] = '.';
        return res;
    }
};