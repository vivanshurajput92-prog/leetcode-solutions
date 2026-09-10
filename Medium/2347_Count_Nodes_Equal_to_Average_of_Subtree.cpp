/*
 * Problem: Count Nodes Equal to Average of Subtree
 * Problem ID: 2347
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 15.8 MB
 * Synced From: LeetCode
 * Date: 2026-09-10
 */

class Solution {
    int ct = 0;
private:
    pair<int,int> check(TreeNode* root){
        if(root == NULL) return {0,0};
        auto left = check(root->left);
        auto right = check(root->right);
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        int target = sum / cnt;
        if(root->val == target) ct++;
        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        check(root);
        return ct;
    }
};