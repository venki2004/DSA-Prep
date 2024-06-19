class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       vector<pair<int,int>>jobs;
       for(int i=0;i<profit.size();i++){
          jobs.push_back({difficulty[i],profit[i]});
       }
        sort(jobs.begin(),jobs.end());
        for(int i=0;i<jobs.size();i++){
           jobs[i+1].second=max(jobs[i+1].second,jobs[i].second);
        }
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int cap=worker[i];
            int l=0;
            int r=jobs.size()-1;
            int prof=0;
            while(l<=r){
                int m=(l+r)/2;
                if(jobs[m].first<=cap){
                    prof=max(prof,jobs[m].second);
                    l=m+1;
                }else{
                    r=m-1;
                }
            }
            ans+=prof;
        }
        return ans;
    }
};
