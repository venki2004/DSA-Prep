class Solution {
    private:
       void dfs(int node,vector<int>adj[],vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis);
        }
       }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj[isConnected.size()+1];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int cnt=0;
        vector<int>vis(isConnected.size()+1,0);
        for(int i=1;i<=isConnected.size();i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
