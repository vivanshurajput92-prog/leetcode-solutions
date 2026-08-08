/*
 * Problem: Path Sum
 * Problem ID: 112
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 21.5 MB
 * Synced From: LeetCode
 * Date: 2026-08-08
 */

class Solution {
private:
    bool f(TreeNode* node,int target){
        if(node->left == nullptr && node->right == nullptr){
            if(target == node->val) return true;
            else return false;
        }
        bool left = false,right = false;
        if(node->left) left = f(node->left,target-node->val);
        if(node->right) right = f(node->right,target-node->val);
        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root == nullptr) return false;
        return f(root,target);
    }
};