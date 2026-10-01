/*
 * Problem: Number of Intersecting Interval Pairs II
 * Problem ID: 4417
 * Difficulty: Medium
 * Language: C++
 * Runtime: 123 ms
 * Memory: 253.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-01
 */

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        long long ct = 0;
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