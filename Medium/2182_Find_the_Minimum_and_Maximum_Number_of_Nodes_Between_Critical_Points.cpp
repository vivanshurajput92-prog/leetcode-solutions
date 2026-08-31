/*
 * Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Problem ID: 2182
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 128.5 MB
 * Synced From: LeetCode
 * Date: 2026-08-31
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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        if(!head->next || !head->next->next) return {-1,-1}; 
        ListNode* temp = head->next;
        ListNode* prev = head;
        int ct = 2;
        while(temp->next){
            if(temp->val > prev->val && temp->val > temp->next->val){
                pos.push_back(ct);
            }
            if(temp->val < prev->val && temp->val < temp->next->val){
                pos.push_back(ct);
            }
            prev = temp;
            ct++;
            temp = temp->next;
        }
        if(pos.size() < 2) return {-1,-1};
        int mini;
        for(int i=1;i<pos.size();i++){
            if(pos[i] - pos[i-1] < mini) mini = pos[i] - pos[i-1];
        }
        return {mini,pos[pos.size()-1] - pos[0]};
    }
};