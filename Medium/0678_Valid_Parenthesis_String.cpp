/*
 * Problem: Valid Parenthesis String
 * Problem ID: 678
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 10.7 MB
 * Synced From: LeetCode
 * Date: 2026-10-04
 */

class Solution {
private:
    int f(int i,int j,string &s,vector<vector<int>> &dp){
        if(j < 0) return 0;
        if(i == s.length()) return j == 0;
        if(dp[i][j] != -1) return dp[i][j];
        bool isValid = false;
        if(s[i] == '(') isValid = f(i+1,j+1,s,dp);
        else if(s[i] == ')') isValid =  f(i+1,j-1,s,dp);
        else{
            bool first = f(i+1,j,s,dp);
            bool second = f(i+1,j+1,s,dp);
            bool third = f(i+1,j-1,s,dp);
            isValid = first || second || third;
        }
        return dp[i][j] = isValid;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,s,dp);
    }
};