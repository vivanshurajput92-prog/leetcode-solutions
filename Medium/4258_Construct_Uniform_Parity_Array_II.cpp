/*
 * Problem: Construct Uniform Parity Array II
 * Problem ID: 4258
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 165.9 MB
 * Synced From: LeetCode
 * Date: 2026-09-03
 */

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool all_even = true;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,nums1[i]);
            if(nums1[i] % 2 == 1) all_even = false;
        }
        if(mini % 2 == 1 || all_even) return true;
        return false;
    }
};