class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& vis,
             vector<int>& pathvis,
             vector<int>& safe) {

        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathvis, safe)) {
                    safe[node] = 0;
                    return true;   // cycle reachable
                }
            }
            else if (pathvis[it] == 1) {
                safe[node] = 0;
                return true;       // cycle detected
            }
        }

        pathvis[node] = 0;  // backtrack
        safe[node] = 1;     // no cycle reachable
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathvis(n, 0), safe(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathvis, safe);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};
