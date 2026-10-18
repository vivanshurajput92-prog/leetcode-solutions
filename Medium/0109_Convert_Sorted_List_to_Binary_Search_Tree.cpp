/*
 * Problem: Convert Sorted List to Binary Search Tree
 * Problem ID: 109
 * Difficulty: Medium
 * Language: C++
 * Runtime: 10 ms
 * Memory: 33.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-18
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* create(vector<int> &arr,int start,int end){
        if(start > end){
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* newNode = new TreeNode(arr[mid]);
        newNode->right = create(arr,mid+1,end);
        newNode->left = create(arr,start,mid-1);
        return newNode;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        return create(arr,0,n-1);
    }
};