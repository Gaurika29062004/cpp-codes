class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && mat[i][j]==0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            dis[row][col] = distance;

            int delrow[4] = {0,-1,0,1};
            int delcol[4] = {-1,0,1,0};

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                vis[nrow][ncol]==0 && mat[nrow][ncol]==1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
        }
        return dis;

    }
};