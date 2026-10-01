/*
 * Problem: Number of Intersecting Interval Pairs I
 * Problem ID: 4418
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 36.5 MB
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
            int lo = i+1,hi = n-1;
            int target = intervals[i][1];
            while(hi - lo > 1){
                int mid = lo + (hi-lo)/2;
                if(intervals[mid][0] > target) hi = mid - 1;
                else lo = mid;
            }
            if(intervals[hi][0] <= target) ct += hi - i;
            else if(intervals[lo][0] <= target) ct += lo - i;
        }
        return ct;
    }
};