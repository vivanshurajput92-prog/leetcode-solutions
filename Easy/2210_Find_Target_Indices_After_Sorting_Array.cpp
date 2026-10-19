/*
 * Problem: Find Target Indices After Sorting Array
 * Problem ID: 2210
 * Difficulty: Easy
 * Language: C++
 * Runtime: 1 ms
 * Memory: 15.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-19
 */

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target) ans.push_back(i);
        }
        return ans;
    }
};