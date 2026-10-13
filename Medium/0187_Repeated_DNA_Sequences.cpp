/*
 * Problem: Repeated DNA Sequences
 * Problem ID: 187
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1310 ms
 * Memory: 451.1 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n <= 10) return {};
        unordered_map<string,int> m;
        string curr = "";
        for(int i=0;i<10;i++){
            curr.push_back(s[i]);
        }
        m[curr]++;
        int j = 9;
        while(j < n-1){
            curr.erase(0, 1);
            j++;
            curr.push_back(s[j]);
            m[curr]++;
        }
        vector<string> ans;
        for(auto &p : m){
            if(p.second > 1) ans.push_back(p.first);
        }
        return ans;
    }
};