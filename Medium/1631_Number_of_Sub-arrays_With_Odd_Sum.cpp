/*
 * Problem: Number of Sub-arrays With Odd Sum
 * Problem ID: 1631
 * Difficulty: Medium
 * Language: C++
 * Runtime: 11 ms
 * Memory: 117.5 MB
 * Synced From: LeetCode
 * Date: 2026-11-15
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int M = 1e9 + 7;
        if(n == 1){
            return nums[0] % 2 == 0 ? 0 : 1;
        }
        vector<int> pf(n);
        pf[0] = nums[0];
        for(int i=1;i<n;i++){
            pf[i] = pf[i-1] + nums[i];
        }
        // 1 3 6 10 15 21 28
        // odd = 3,even = 3
        int even_ct = 0,odd_ct = 0;
        for(int i=0;i<n;i++){
            if(pf[i] % 2 == 0) even_ct++;
            else odd_ct++;
        }
        int ans = odd_ct;
        for(int i=0;i<n;i++){
            if(pf[i] % 2 == 0){
                even_ct--;
                ans = (ans + odd_ct) % M;
            }
            else{
                odd_ct--;
                ans = (ans + even_ct) % M;
            }
        }
        return ans;
    }
};