/*
 * Problem: Find Missing Elements
 * Problem ID: 4107
 * Difficulty: Easy
 * Language: C++
 * Runtime: 4 ms
 * Memory: 33.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++) s.insert(nums[i]);
        for(int i=nums[0];i<=nums[nums.size()-1];i++){
            if(s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};