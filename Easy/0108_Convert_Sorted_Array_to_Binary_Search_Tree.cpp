/*
 * Problem: Convert Sorted Array to Binary Search Tree
 * Problem ID: 108
 * Difficulty: Easy
 * Language: C++
 * Runtime: 7 ms
 * Memory: 22.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-10
 */

class Solution {
private:
    TreeNode* makeTree(vector<int> &nums,int lo,int hi){
        if(lo > hi){
            return NULL;
        }
        int mid = (lo + hi) /2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = makeTree(nums,lo,mid-1);
        node->right = makeTree(nums,mid+1,hi);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return makeTree(nums,0,n-1);
    }
};