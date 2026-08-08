/*
 * Problem: Path Sum II
 * Problem ID: 113
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 21 MB
 * Synced From: LeetCode
 * Date: 2026-08-08
 */

class Solution {
vector<vector<int>> ans;
private:
    void f(TreeNode* node,int target,vector<int> &used){
        if(node->left == nullptr && node->right == nullptr){
            if(target == node->val){
                used.push_back(node->val);
                ans.push_back(used);
                used.pop_back();
                return;
            }
            else return;
        }
        if(node->left){
            used.push_back(node->val);
            f(node->left,target-node->val,used);
            used.pop_back();
        }
        if(node->right){
            used.push_back(node->val);
            f(node->right,target-node->val,used);
            used.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == nullptr) return {};
        vector<int> used;
        f(root,target,used);
        return ans;
    }
};