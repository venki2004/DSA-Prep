class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>cop=grid;
        queue<pair<pair<int,int>,int>>q;
     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ans=max(ans,t);
            q.pop();
            int a[]={0,0,-1,1};
            int b[]={-1,1,0,0};
            for(int i=0;i<4;i++){
                int nr=r+a[i];
                int nc=c+b[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && cop[nr][nc]==1){
                    q.push({{nr,nc},t+1});
                    cop[nr][nc]=2;
                }
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(cop[i][j]==1){
                 flag=false;
              }
            }
        }
        if(flag) return ans;
        return -1;
    }
};
