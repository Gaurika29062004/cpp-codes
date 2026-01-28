class Solution {
public:
    bool check(int src ,vector<vector<int>>& graph , vector<int> &vis){
        queue<int>q;
        q.push(src);
        vis[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(vis[it]== -1){
                    vis[it] = !vis[node];
                    q.push(it);
                }
                else if(vis[it]==vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,-1);
        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(!check(i,graph,vis)) return false;
            }
        }
        return true;
    }
};