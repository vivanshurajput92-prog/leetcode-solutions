/*
 * Problem: Minimum Operations to Sort a Permutation
 * Problem ID: 4184
 * Difficulty: Medium
 * Language: C++
 * Runtime: 4 ms
 * Memory: 141.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-22
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int ct_1 = 0;
        int ct_n1 = 0;
        int ind_0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                ind_0 = i;
                break;
            }
        }
        int diff = 0;
        for(int i=0;i<n;i++){
            if(i < n-1){
                if(nums[i+1] - nums[i] == 1){
                    ct_1++;
                    diff = 1;
                }
                if(nums[i+1] - nums[i] == -1){
                    ct_n1++;
                    diff = -1;
                }
            }
            if(i == n-1){
                if(nums[0] - nums[i] == 1) ct_1++;
                if(nums[0] - nums[i] == -1) ct_n1++;
            }
        }
        if(ct_1 == n-1 || ct_n1 == n-1){
            if(diff == -1){
                ind_0 = n-ind_0-1;
                return min(n-ind_0,ind_0) + 1;
            }
            if(diff == 1){
                return min(ind_0, n - ind_0 + 2);
            }
        }
        return -1;
    }
};