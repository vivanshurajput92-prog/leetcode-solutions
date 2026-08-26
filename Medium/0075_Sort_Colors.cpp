/*
 * Problem: Sort Colors
 * Problem ID: 75
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 12 MB
 * Synced From: LeetCode
 * Date: 2026-08-26
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ct_0 = 0;
        int ct_1 = 0;
        int ct_2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) ct_0++;
            else if(nums[i] == 1) ct_1++;
            else if(nums[i] == 2) ct_2++;
        }
        vector<int> ans(n);
        int i = 0;
        while(ct_0){
            ans[i] = 0;
            ct_0--;
            i++;
        }
        while(ct_1){
            ans[i] = 1;
            ct_1--;
            i++;
        }
        while(ct_2){
            ans[i] = 2;
            ct_2--;
            i++;
        }
        nums = ans;
    }
};