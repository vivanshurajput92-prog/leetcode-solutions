/*
 * Problem: Number of Intersecting Interval Pairs I
 * Problem ID: 4418
 * Difficulty: Easy
 * Language: C++
 * Runtime: 8 ms
 * Memory: 36.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-01
 */

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int ct = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intervals[j][0] <= intervals[i][1]) ct++;
            }
        }
        return ct;
    }
};