/*
 * Problem: Contains Duplicate
 * Problem ID: 217
 * Difficulty: Easy
 * Language: C++
 * Runtime: 32 ms
 * Memory: 82.9 MB
 * Synced From: LeetCode
 * Date: 2026-09-09
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { 
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};