/*
 * Problem: Loud and Rich
 * Problem ID: 881
 * Difficulty: Medium
 * Language: C++
 * Runtime: 73 ms
 * Memory: 65.2 MB
 * Synced From: LeetCode
 * Date: 2026-10-04
 */

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto &edge : richer){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> path(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int par = q.front();
                path[i].push_back(par);
                q.pop();
                for(int &child : adj[par]){
                    if(vis[child] == 0){
                        q.push(child);
                        vis[child] = 1;
                    }
                }
            }
            for(int i=0;i<n;i++) vis[i] = 0;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int mn = INT_MAX;
            int min_idx;
            for(int j : path[i]){
                if(quiet[j] < mn){
                    mn = quiet[j];
                    min_idx = j;
                }
            }
            ans[i] = min_idx;
        }
        return ans;
    }
};