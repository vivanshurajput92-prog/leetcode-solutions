/*
 * Problem: Combinations
 * Problem ID: 77
 * Difficulty: Medium
 * Language: C++
 * Runtime: 75 ms
 * Memory: 82.4 MB
 * Synced From: LeetCode
 * Date: 2026-10-08
 */

class Solution {
    vector<vector<int>> ans;
private:
    void f(int start,int n,int k,vector<int> &curr){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            f(i+1,n,k,curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        f(1,n,k,curr);
        return ans;
    }
};