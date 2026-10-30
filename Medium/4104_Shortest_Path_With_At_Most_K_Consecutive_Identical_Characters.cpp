/*
 * Problem: Shortest Path With At Most K Consecutive Identical Characters
 * Problem ID: 4104
 * Difficulty: Medium
 * Language: C++
 * Runtime: 293 ms
 * Memory: 318.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-30
 */

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n == 1 && edges.size() == 0) return 0; 
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        set<vector<int>> s;
        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        s.insert({0,0,1});
        dist[0][1] = 0;
        while(!s.empty()){
            auto it = s.begin();
            int distance = (*it)[0];
            int node = (*it)[1];
            int cst = (*it)[2];
            s.erase(it);
            if(distance > dist[node][cst]) continue;
            if(node == n-1) return distance;
            for(auto &child : adj[node]){
                int adjNode = child.first;
                int wt = child.second;
                int consecutive = cst;
                if(labels[node] == labels[adjNode]) consecutive++;
                else consecutive = 1;
                if(consecutive <= k && wt + distance < dist[adjNode][consecutive]){
                    dist[adjNode][consecutive] = wt + distance;
                    s.insert({dist[adjNode][consecutive],adjNode,consecutive});
                }
            }
        }
        return -1;
    }
};