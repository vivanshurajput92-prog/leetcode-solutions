/*
 * Problem: Length of Longest Subarray With at Most K Frequency
 * Problem ID: 3225
 * Difficulty: Medium
 * Language: C++
 * Runtime: 72 ms
 * Memory: 149.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-12
 */

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        int i = 0;
        for(int j=0;j<n;j++){
            m[nums[j]]++;
            while(m[nums[j]] > k){
                m[nums[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};