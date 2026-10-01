/*
 * Problem: Valid Parentheses
 * Problem ID: 20
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-01
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool present = true;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()){
                    present = false;
                    break;
                }
                char c = st.top();
                if((c != '(' && s[i] == ')') || (s[i] == '}' && c != '{' ) || (s[i] == ']' && c !=  '[')){
                    present = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            present = false;
        }
        return present;
    }
};