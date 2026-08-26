/*
 * Problem: Majority Element
 * Problem ID: 169
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 28.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-26
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 0,val = 0;
        for(int i=0;i<nums.size();i++){
            if(ct == 0) val = nums[i];
            ct += val == nums[i] ? 1 : -1;
        }
        return val;
    }
};