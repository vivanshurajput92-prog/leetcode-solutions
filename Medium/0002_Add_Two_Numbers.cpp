/*
 * Problem: Add Two Numbers
 * Problem ID: 2
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 77 MB
 * Synced From: LeetCode
 * Date: 2026-10-01
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* temp = nullptr;
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            int val = sum % 10;
            if(ans == nullptr){
                ListNode* newNode = new ListNode(val);
                ans = newNode;
                temp = ans;
            }
            else{
                temp->next = new ListNode(val);
                temp = temp->next;
            }
        }
        if(carry != 0){
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        return ans;
    }
};