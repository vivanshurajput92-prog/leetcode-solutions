/*
 * Problem: Next Greater Element II
 * Problem ID: 503
 * Difficulty: Medium
 * Language: C++
 * Runtime: 6 ms
 * Memory: 28.6 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        int n = nums2.size();
        stack<int> s;
        s.push(nums2[n-1]);
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums2[i] >= s.top()) s.pop();
            s.push(nums2[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums2[i] >= s.top()) s.pop();
            if(!s.empty()) ans[i] = s.top();
            else ans[i] = -1;
            s.push(nums2[i]);
        }
        return ans;
    }
};