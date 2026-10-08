/*
 * Problem: Remove Outermost Parentheses
 * Problem ID: 1078
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 10.8 MB
 * Synced From: LeetCode
 * Date: 2026-10-08
 */

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int balance = 1;
        vector<string> v;
        string element = "(";
        for(int i=1;i<n;i++){
            if(balance == 0){
                v.push_back(element);
                element = "";
            }
            element += s[i];
            if(s[i] == '(') balance++;
            else balance--;
        }
        if(balance == 0){
            v.push_back(element);
            element = "";
        }
        string ans = "";
        for(string &ele : v){
            if(ele.length() == 2) continue;
            else ans += ele.substr(1,ele.length()-2);
        }
        return ans;
    }
};