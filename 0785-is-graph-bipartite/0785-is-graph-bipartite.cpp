class Solution {
public:
    bool dfs(int node,vector<int>& colour,vector<vector<int>>& graph){
        for(auto it : graph[node]){
            if(colour[it]==-1){
                colour[it] = !colour[node];
                if(dfs(it,colour,graph)==false) return false;
            }
            else if(colour[it]==colour[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> colour(m,-1);
        for(int i=0;i<m;i++){
            if(colour[i]==-1){
                colour[i] = 0;
                if(dfs(i,colour,graph)==false) return false;
            }
        }
        return true;
    }
};