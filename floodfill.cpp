class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans=image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vis[sr][sc]=1;
        q.push({sr,sc});
        ans[sr][sc]=color;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int a[]={-1,1,0,0};
            int b[]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nr=r+a[i];
                int nc=c+b[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[r][c]==image[nr][nc]){
                    ans[nr][nc]=color;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return ans;
    }
};
