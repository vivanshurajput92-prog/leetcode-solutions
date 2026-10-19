/*
 * Problem: Search a 2D Matrix II
 * Problem ID: 240
 * Difficulty: Medium
 * Language: C++
 * Runtime: 104 ms
 * Memory: 18.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-19
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n < m){
            for(int i=0;i<n;i++){
                int lo = 0,hi = m-1;
                while(hi - lo > 1){
                    int mid = lo + (hi - lo)/2;
                    if(matrix[i][mid] < target) lo = mid+1;
                    else if(matrix[i][mid] > target) hi = mid-1;
                    else return true;
                }
                if(matrix[i][lo] == target) return true;
                if(matrix[i][hi] == target) return true;
            }
        }
        else{
            for(int i=0;i<m;i++){
                int lo = 0,hi = n-1;
                while(hi - lo > 1){
                    int mid = lo + (hi - lo)/2;
                    if(matrix[mid][i] < target) lo = mid+1;
                    else if(matrix[mid][i] > target) hi = mid-1;
                    else return true;
                }
                if(matrix[lo][i] == target) return true;
                if(matrix[hi][i] == target) return true;
            }
        }
        return false;
    }
};
