class Solution {
public:
    
    int min(int a,int b){
        if(a<=b) return a;
        return b;
    }
    
    int solve(int partition,vector<int>& arr, int k,vector<int> &dp){
        if(partition==arr.size()) return 0;
        
        if(dp[partition]!=-1) return dp[partition];
        
        int len =0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        
        for(int i=partition;i<min(partition+k,arr.size());i++){
            len++;
            maxi = max(maxi,arr[i]);
            
            int sum = maxi*len + solve(i+1,arr,k,dp);
            
            ans=max(ans,sum);
            
        }
        
        return dp[partition]=ans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,-1);
        return solve(0,arr,k,dp);
    }
};