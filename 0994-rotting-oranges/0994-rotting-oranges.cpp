class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
        }
    } 
    int tm = 0;
    int drow[] = {0,-1,0,1};
    int dcol[] = {-1,0,1,0};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(t,tm);
        q.pop();
        for(int i=0;i<4;i++){
            int ni = row + drow[i];
            int nj = col + dcol[i];
            if(ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj]!=2 && grid[ni][nj] == 1){
                q.push({{ni,nj},t+1});
                vis[ni][nj] = 2;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return tm;
    }
};