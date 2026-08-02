/*
 * Problem: Subsets II
 * Problem ID: 90
 * Difficulty: Medium
 * Language: C++
 * Runtime: 6 ms
 * Memory: 18.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
public:
    set<vector<int>> ans;
    
    void sub(vector<int> nums, vector<int> used, int i, int n){
        if (i >= n)
        {
            ans.insert(used);
            return;
        }

        sub(nums, used, i + 1, n);
        used.push_back(nums[i]);
        sub(nums, used, i + 1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> used;
        sort(nums.begin(),nums.end());
        sub(nums, used, 0, nums.size());
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};