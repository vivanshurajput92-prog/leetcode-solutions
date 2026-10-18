/*
 * Problem: Convert Sorted List to Binary Search Tree
 * Problem ID: 109
 * Difficulty: Medium
 * Language: C++
 * Runtime: 8 ms
 * Memory: 33.5 MB
 * Synced From: LeetCode
 * Date: 2026-10-18
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