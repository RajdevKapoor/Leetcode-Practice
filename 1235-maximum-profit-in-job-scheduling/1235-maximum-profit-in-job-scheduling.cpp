class Solution {
public:
    long int getNext(vector<vector<int>>&jobs,int low,int target){
        int high = jobs.size()-1;
       long int res=high+2;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(jobs[mid][0]>=target){
                res= mid;
                high= mid-1;
            }
            else
             low= mid+1;
        }
        return res;
    }
    int solve(vector<vector<int>>&jobs,int idx,vector<int>&dp){
        if(idx>=jobs.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long int nextIndex= getNext(jobs,idx+1,jobs[idx][1]);
        int taken= jobs[idx][2] + solve(jobs,nextIndex,dp);
        int not_taken= solve(jobs,idx+1,dp);
        return dp[idx]=max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        vector<vector<int>>jobs(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            jobs[i][0]=startTime[i];
            jobs[i][1]=endTime[i];
            jobs[i][2]=profit[i];
        }
        sort(jobs.begin(),jobs.end(),[&](auto &a,auto &b){
            return a[0]<=b[0];
        });
        vector<int>dp(n+1,-1);
        return solve(jobs,0,dp);
    }
};