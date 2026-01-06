class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>&adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>>adj(n);
    for(int u=0;u<isConnected.size();u++){
        for(int v=0;v<isConnected[0].size();v++){
            if(isConnected[u][v]==1 && u!=v){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    vector<int> vis(n,0);
    int count = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i,vis,adj);
        }
    }
    return count; 
    }
};