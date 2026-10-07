/*
 * Problem: Permutations II
 * Problem ID: 47
 * Difficulty: Medium
 * Language: C++
 * Runtime: 171 ms
 * Memory: 34.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-07
 */

class Solution {
    set<vector<int>> ans;
private:
    void f(vector<int> &nums,vector<int> &curr,unordered_set<int> &used){
        if(curr.size() == nums.size()){
            ans.insert(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used.find(i) == used.end()){
                used.insert(i);
                curr.push_back(nums[i]);
                f(nums,curr,used);
                curr.pop_back();
                used.erase(i);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        unordered_set<int> used;
        f(nums,curr,used);
        vector<vector<int>> f_ans;
        for(vector<int> sub_ans : ans){
            f_ans.push_back(sub_ans);
        }
        return f_ans;
    }
};