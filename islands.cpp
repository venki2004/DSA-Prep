class Solution {
private:
     void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int n,int m){
        queue<pair<int,int>>q;
        vis[row][col]=1;
        q.push({row,col});
        while(!q.empty()){
          int r=q.front().first;
          int c=q.front().second;
          q.pop();
          int a[]={-1,1,0,0};
          int b[]={0,0,-1,1};
          for(int i=0;i<4;i++){
            int nr=r+a[i];
            int nc=c+b[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0){
              q.push({nr,nc});
              vis[nr][nc]=1;
            }
          }
        }
     }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                  cnt++;
                  bfs(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
    }
};
