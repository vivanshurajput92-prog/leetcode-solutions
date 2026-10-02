/*
 * Problem: Generate Parentheses
 * Problem ID: 22
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 15.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-02
 */

class Solution {
private:
    void create(vector<string> &ans,int op,int cl,int sc,string s){
        if(cl == 0 && op == 0){
            ans.push_back(s);
            return;
        }
        if(sc == 0 && op > 0) create(ans,op-1,cl,sc+1,s+'(');
        if(sc > 0){
            if(op > 0) create(ans,op-1,cl,sc+1,s+'(');
            if(cl > 0) create(ans,op,cl-1,sc-1,s+')');
        }
    }
public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        create(ans,n,n,0,"");
        return ans;
    }
};