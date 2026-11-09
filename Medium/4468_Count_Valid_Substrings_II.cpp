/*
 * Problem: Count Valid Substrings II
 * Problem ID: 4468
 * Difficulty: Medium
 * Language: C++
 * Runtime: 51 ms
 * Memory: 52.7 MB
 * Synced From: LeetCode
 * Date: 2026-11-09
 */

class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.length();
        vector<int> nexta(n+1,n),nextb(n+1,n),nextc(n+1,n);
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'a'){
                nexta[i] = i;
                nextb[i] = nextb[i+1];
                nextc[i] = nextc[i+1];
            }
            if(s[i] == 'b'){
                nextb[i] = i;
                nexta[i] = nexta[i+1];
                nextc[i] = nextc[i+1];
            }
            if(s[i] == 'c'){
                nextc[i] = i;
                nextb[i] = nextb[i+1];
                nexta[i] = nexta[i+1];
            }
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            int na = n,nb = n,nc = n;
            if(nexta[i] != n){
                na = nexta[i];
            }
            if(na != n && nextb[na] != n){
                nb = nextb[na];
            }
            if(nb != n && nextc[nb] != n){
                nc = nextc[nb];
            }
            if(nc == n){
                ans += 1LL * (n-i);
            }
            else{
                ans += 1LL * (nc-i);
            }
        }
        return ans;
    }
};