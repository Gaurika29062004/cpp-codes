class Solution {
public:
    void dfs(int row , int col ,vector<vector<int>> &vis,vector<vector<char>> &board){
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        int delrow[4] = {0,-1,0,1};
        int delcol[4] = {-1,0,1,0};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
            !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && (i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                    dfs(i,j,vis,board);
                }
                }
            }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};