class Solution {
public:
    
    int helper(int i,int j,vector<int> &cuts,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int len=cuts[j+1]-cuts[i-1];
        int mini=1e9;
        for(int ind=i;ind<=j;++ind)
        {
            int cost=len+helper(i,ind-1,cuts,dp)+helper(ind+1,j,cuts,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int x=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(x+1,vector<int> (x+1,-1));
        return helper(1,x,cuts,dp);
    }
};