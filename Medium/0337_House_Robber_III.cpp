/*
 * Problem: House Robber III
 * Problem ID: 337
 * Difficulty: Medium
 * Language: C++
 * Runtime: 19 ms
 * Memory: 30 MB
 * Synced From: LeetCode
 * Date: 2026-08-07
 */

class Solution {
private:
    int f(TreeNode *node,bool taken,auto &dp){
        if(node == NULL) return 0;
        if(dp.find({node,taken}) != dp.end()) return dp[{node,taken}];
        int take = INT_MIN;
        if(!taken) take = node->val + f(node->left,true,dp) + f(node->right,true,dp);
        int notTake = f(node->left,false,dp) + f(node->right,false,dp);
        return dp[{node,taken}] = max(take,notTake);
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int> dp;
        return f(root,false,dp);
    }
};