/*
 * Problem: Boats to Save People
 * Problem ID: 917
 * Difficulty: Medium
 * Language: C++
 * Runtime: 24 ms
 * Memory: 45.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-08
 */

class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i=0,j=nums.size()-1;
        while(i <= j){
            if(nums[i] + nums[j] <= limit){
                ans++;
                i++;
                j--;
            }
            else{
                ans++;j--;
            }
        }
        return ans;
    }
};