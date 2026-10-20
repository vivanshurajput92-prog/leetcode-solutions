/*
 * Problem: Find the Duplicate Number
 * Problem ID: 287
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1 ms
 * Memory: 67.5 MB
 * Synced From: LeetCode
 * Date: 2026-10-20
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> present(n+1,0);
        for(int i=0;i<nums.size();i++){
            present[nums[i]]++;
        }
        for(int i=0;i<present.size();i++){
            if(present[i] >= 2) return i;
        }
        return -1;
    }
};