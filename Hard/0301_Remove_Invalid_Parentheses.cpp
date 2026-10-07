/*
 * Problem: Remove Invalid Parentheses
 * Problem ID: 301
 * Difficulty: Hard
 * Language: C++
 * Runtime: 173 ms
 * Memory: 11.6 MB
 * Synced From: LeetCode
 * Date: 2026-10-07
 */

class Solution {
    unordered_set<string> ans;
private:
    void f(int i,string &s,int open,string &curr,int &ct,int &char_ct){
        if(i == s.length()){
            if(open == 0 && curr.size() == s.length() - ct) ans.insert(curr);
            return;
        }
        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            f(i+1,s,open,curr,ct,char_ct);
            curr.pop_back();
        }
        else{
            f(i+1,s,open,curr,ct,char_ct);
            if(s[i] == '('){
                open++;
                curr.push_back(s[i]);
                f(i+1,s,open,curr,ct,char_ct);
                curr.pop_back();
            }
            else{
                if(open > 0){
                    open--;
                    curr.push_back(s[i]);
                    f(i+1,s,open,curr,ct,char_ct);
                    curr.pop_back();
                }
                else return;
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int ct = 0;
        int char_ct = 0;
        int openCount = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') openCount++;
            else if(s[i] == ')'){
                openCount--;
            }
            else char_ct++;
            if(openCount < 0){
                openCount = 0;
                ct++;
            }
        }
        ct += openCount;
        string curr = "";
        f(0,s,0,curr,ct,char_ct);
        vector<string> final_ans;
        for(string str : ans){
            final_ans.push_back(str);
        }
        return final_ans;
    }
};