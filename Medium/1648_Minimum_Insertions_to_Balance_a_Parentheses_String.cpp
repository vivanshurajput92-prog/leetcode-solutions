/*
 * Problem: Minimum Insertions to Balance a Parentheses String
 * Problem ID: 1648
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 15.5 MB
 * Synced From: LeetCode
 * Date: 2026-10-09
 */

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int ct = 0;
        int openCt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') openCt++;
            else if(i < n-1 && s[i] == ')' && s[i+1] == ')'){
                openCt--;
                i++;
            }
            else{
                ct++;
                openCt--;
            }
            if(openCt < 0){
                openCt = 0;
                ct++;
            }
        }
        ct += (2 * openCt);
        return ct;
    }
};