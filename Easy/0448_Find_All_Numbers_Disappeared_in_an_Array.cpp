/*
 * Problem: Find All Numbers Disappeared in an Array
 * Problem ID: 448
 * Difficulty: Easy
 * Language: C++
 * Runtime: 41 ms
 * Memory: 64.1 MB
 * Synced From: LeetCode
 * Date: 2026-09-18
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(s.find(i+1) == s.end()) ans.push_back(i+1);
        }
        return ans;
    }
};