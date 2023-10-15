class Solution {
public:
    int mod =1e9 + 7;
    int solve(int i, int n, int steps, int k,vector<vector<int>>  &mp){
        
        if(i<0 or i>=n or k>steps){
            return 0;
        }
        
        if(mp[i][k]!=-1){
            return mp[i][k];
        }
        
        if(k==steps){
            if(i==0) {
                return 1;
            }
            return 0;
        }
        int op1 =solve(i+1,n,steps,k+1,mp)%mod;
        int op2 =solve(i-1,n,steps,k+1,mp)%mod;
        int op3 =solve(i,n,steps,k+1,mp)%mod;
        
        mp[i][k]=((op1 + op2)%mod +op3)%mod;
        return mp[i][k];
        
    }
    
    int numWays(int steps, int n) {
        vector<vector<int>> mp(501,vector<int>(501,-1));
        return solve(0,n,steps,0,mp);
    }
};