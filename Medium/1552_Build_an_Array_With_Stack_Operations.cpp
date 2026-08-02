/*
 * Problem: Build an Array With Stack Operations
 * Problem ID: 1552
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 10.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-02
 */

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(j >= target.size()) return ans;
            if(target[j] == i){
                ans.push_back("Push");
                j++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};