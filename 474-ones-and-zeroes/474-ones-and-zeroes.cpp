class Solution {
public:
    int dp[601][101][101];
    
    int solve(vector<string>& strs, int m, int n,int i){
        
        if(i>=strs.size() or (m==0 and n==0)){
            return 0;
        }
        
        
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int ans=0;
        
        int zero = 0;
        int one = 0;
        for(char c:strs[i]){
            if(c=='0'){
                zero++;
            }else{
                one++;
            }
        }
        
        //take
        if(zero<=m and one<=n){
            int op1 = 1 + solve(strs,m-zero,n-one,i+1);
            ans=max(ans,op1);
        }
        
        
        //not take
        int op2 = solve(strs,m,n,i+1);
        ans=max(ans,op2);
    
        return dp[i][m][n]=ans;
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp, -1, sizeof(dp));
        return solve(strs,m,n,0);
    }
};