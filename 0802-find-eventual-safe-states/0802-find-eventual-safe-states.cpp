class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,
    vector<vector<int>>& graph,vector<int>& safe){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,graph,safe)==true){
                    safe[node]= 0;
                    return true;
                }
            }
            else if(pathvis[it]==1){
                safe[node]=0;
                return true;
            }
        }
        safe[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> vis(m,0) , pathvis(m,0) , safe(m,0);
        for(int i=0;i<m;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,graph,safe);
            }
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};