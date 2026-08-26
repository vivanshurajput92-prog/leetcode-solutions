/*
 * Problem: Shortest and Lexicographically Smallest Beautiful String
 * Problem ID: 3150
 * Difficulty: Medium
 * Language: C++
 * Runtime: 3 ms
 * Memory: 9.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-26
 */

class Solution {
private:
    string lexo(string &ans,string &curr){
        if(ans.length() < curr.length()) return ans;
        if(ans.length() > curr.length()) return curr;
        for(int i=0;i<ans.length();i++){
            if(ans[i] < curr[i]) return ans;
            if(curr[i] < ans[i]) return curr;
        }
        return ans;
    }
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans="$";
        for(int i=0;i<n;i++){
            int ones = 0;
            string curr;
            for(int j=i;j<n;j++){
                curr.push_back(s[j]);
                if(s[j] == '1') ones++;
                if(ones == k){
                    if(ans == "$") ans = curr;
                    ans = lexo(ans,curr);
                    break;
                }
            }
        }
        return ans == "$" ? "" : ans;
    }
};