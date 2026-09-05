/*
 * Problem: Smallest Stable Index II
 * Problem ID: 4285
 * Difficulty: Medium
 * Language: C++
 * Runtime: 14 ms
 * Memory: 202.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-05
 */

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stability(n);
        int max_val = INT_MIN,min_val = INT_MAX;
        for(int i=0;i<n;i++){
            max_val = max(max_val,nums[i]);
            stability[i] = max_val;
        }
        for(int i=n-1;i>=0;i--){
            min_val = min(min_val,nums[i]);
            stability[i] -= min_val;
        }
        for(int i=0;i<n;i++){
            if(stability[i] <= k) return i;
        }
        return -1;
    }
};