/*
 * Problem: Remove Methods From Project
 * Problem ID: 3561
 * Difficulty: Medium
 * Language: C++
 * Runtime: 160 ms
 * Memory: 301.1 MB
 * Synced From: LeetCode
 * Date: 2026-08-05
 */

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> sus(n,0);
        //vector<int> vis(n,0);
        sus[k] = 1;
        queue<int> q1;
        q1.push(k);
        while(!q1.empty()){
            int vertex = q1.front();
            q1.pop();
            for(int &child : adj[vertex]){
                if(sus[child]) continue;
                q1.push(child);
                //vis[child] = 1;
                sus[child] = 1;
            }
        }
        // queue<int> q;
        bool found = false;
        for(int i=0;i<n;i++){
            if(sus[i] == 0){
                for(int &child : adj[i]){
                    if(sus[child] == 0) continue;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();
        //     for(int &child : adj[node]){
        //         if(sus[child] == 0) continue;
        //         q.push(child);
        //         sus[child] = 0;
        //     }
        // }
        vector<int> res;
        if(!found){
            for(int i=0;i<n;i++){
                if(!sus[i]) res.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                res.push_back(i);
            }
        }
        return res;
    }
};