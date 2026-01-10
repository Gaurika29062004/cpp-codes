class Solution {
private:
    void bfs(int row,int col,int color,int originalval,vector<vector<int>> &vis,vector<vector<int>> &image){
        vis[row][col] = 1;
        image[row][col] = color;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = image.size();
        int m = image[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[4] = {0,-1,0,1};
            int delcol[4] = {-1,0,1,0};

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
                && image[nrow][ncol] == originalval){
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    int originalval = image[sr][sc];
    vector<vector<int>> vis(n,vector<int>(m,0));
    if(!vis[sr][sc] && image[sr][sc]!=color){
        bfs(sr,sc,color,originalval,vis,image);
    }
    return image;
    }
};