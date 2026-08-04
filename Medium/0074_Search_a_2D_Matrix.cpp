/*
 * Problem: Search a 2D Matrix
 * Problem ID: 74
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 13.5 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int lo = 0;
        int hi = m*n - 1;
        while(hi - lo >= 1){
            int mid = lo + (hi - lo)/2;
            int i = mid/n;
            int j = mid % n;
            if(matrix[i][j] < target) lo = mid + 1;
            else hi = mid;
        }
        if(matrix[lo/n][lo%n] == target) return true;
        if(matrix[hi/n][hi%n] == target) return true;
        return false;
    }
};