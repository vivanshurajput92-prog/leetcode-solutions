/*
 * Problem: Subsets II
 * Problem ID: 90
 * Difficulty: Medium
 * Language: C++
 * Runtime: 8 ms
 * Memory: 18.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
public:
    set<vector<int>> ans;
    
    void sub(vector<int> nums, vector<int> used, int i, int n){
        if (i >= n)
        {
            sort(used.begin(), used.end());
            ans.insert(used);
            return;
        }

        sub(nums, used, i + 1, n);
        used.push_back(nums[i]);
        sub(nums, used, i + 1, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> used;
        sub(nums, used, 0, nums.size());

        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};