/*
 * Problem: Next Greater Element I
 * Problem ID: 496
 * Difficulty: Easy
 * Language: C++
 * Runtime: 3 ms
 * Memory: 12.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-04
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> s;
        s.push(nums2[n-1]);
        unordered_map<int,int> ans;
        ans[nums2[n-1]] = -1;
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && nums2[i] > s.top()) s.pop();
            if(!s.empty()) ans[nums2[i]] = s.top();
            else ans[nums2[i]] = -1;
            s.push(nums2[i]);
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(ans[nums1[i]]);
        }
        return res;
    }
};