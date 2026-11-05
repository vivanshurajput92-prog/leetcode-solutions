/*
 * Problem: Min Cost to Connect All Points
 * Problem ID: 1706
 * Difficulty: Medium
 * Language: C++
 * Runtime: 224 ms
 * Memory: 62.9 MB
 * Synced From: LeetCode
 * Date: 2026-11-05
 */

class dsubysize{
     vector<int> size,par;
public:
  dsubysize(int n){
      size.resize(n+1,1);
      for(int i=0;i<=n;i++){
          par.push_back(i);
      }
  }
  int findpar(int u){
      if(par[u] == u) return u;
      return par[u] = findpar(par[u]);
  }
  void unionBySize(int u,int v){
      int par_u = findpar(u);
      int par_v = findpar(v);
      if(par_v == par_u) return;
      if(size[par_u] > size[par_v]){
          par[par_v] = par_u;
          size[par_u] += size[par_v];
      }
      else{
          par[par_u] = par_v;
          size[par_v] += size[par_u];
      }
  }
};

class Solution {
  private:
  public:
    int minCostConnectPoints(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<pair<int,pair<int,int>>> s; 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                s.push_back({dist,{i,j}});
            }
        }
        sort(s.begin(),s.end());
        dsubysize ds(n);
        int ans = 0;
        int ct = 0;
        for(int i=0;i<s.size();i++){
            if(ct == n-1) break;
            if(ds.findpar(s[i].second.first) != ds.findpar(s[i].second.second)){
                ans += s[i].first;
                ct++;
                ds.unionBySize(s[i].second.first,s[i].second.second);
            }
        }
        return ans;
    }
};