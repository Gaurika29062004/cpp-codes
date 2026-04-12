class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>>vis(m,vector<int>(n,-1));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                vis[i][j] = 0;
                q.push({{i,j},0});
            }
        }
    } 
    int delr[4] = {0,-1,0,1};
    int delc[4] = {-1,0,1,0};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==-1){
                vis[nrow][ncol] = dist+1;
                q.push({{nrow,ncol},dist+1});
            }
        }
    } 
    return vis;
    }
};