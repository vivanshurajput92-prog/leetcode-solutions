/*
 * Problem: Longest Valid Parentheses
 * Problem ID: 32
 * Difficulty: Hard
 * Language: C++
 * Runtime: 2 ms
 * Memory: 11.9 MB
 * Synced From: LeetCode
 * Date: 2026-10-03
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = INT_MIN;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans,i-st.top());
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};