 int mod=1000000007;
 class Solution {
 public:
     long long solve(int remPickup, int remDel, int n, vector<vector<int>>& dp)
     {
         if(remPickup==0 && remDel==0) return 1;
         if(dp[remPickup][remDel]!=-1) return dp[remPickup][remDel];
         long long pickup=0;
         if(remPickup>0) pickup=(remPickup*solve(remPickup-1,remDel,n,dp))%mod;
         long long del=0;
         if(remDel-remPickup>0) del=((remDel-remPickup)*solve(remPickup,remDel-1,n,dp))%mod;
         return dp[remPickup][remDel]=(pickup+del)%mod;
     }
     int countOrders(int n) {
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
         return (int)solve(n,n,n,dp);
     }
 };