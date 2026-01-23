class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> adj(n);
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    vector<int> vis(n,0);
    q.push(source);
    vis[source] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == destination){
            return true;
            break;
        }
        for(auto it : adj[node]){
            if(vis[it]!=1){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return false;
    }
};