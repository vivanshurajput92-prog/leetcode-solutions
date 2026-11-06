/*
 * Problem: Count Zero Request Servers
 * Problem ID: 2833
 * Difficulty: Medium
 * Language: C++
 * Runtime: 46 ms
 * Memory: 199.1 MB
 * Synced From: LeetCode
 * Date: 2026-11-06
 */

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int qSize = queries.size();
        vector<pair<int, int>> sortedQueries(qSize);
        for (int i = 0; i < qSize; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> ans(qSize);
        vector<int> serverFreq(n + 1, 0);
        int activeServers = 0;
        int left = 0, right = 0;
        int logSize = logs.size();

        for (auto& [qTime, idx] : sortedQueries) {
            while (right < logSize && logs[right][1] <= qTime) {
                int serverId = logs[right][0];
                if (serverFreq[serverId] == 0) {
                    activeServers++;
                }
                serverFreq[serverId]++;
                right++;
            }
            while (left < logSize && logs[left][1] < qTime - x) {
                int serverId = logs[left][0];
                serverFreq[serverId]--;
                if (serverFreq[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};