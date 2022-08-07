class Solution {
public:
    int dp[20003][150];
    int mod = 1e9+7;
    int rec(int i,int& n,char prev){
        if(i==n) return 1;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0;
        ans1 = rec(i+1,n,'a');
        ans2 = rec(i+1,n,'e');
        ans3 = rec(i+1,n,'i');
        ans4 = rec(i+1,n,'o');
        ans5 = rec(i+1,n,'u');
        if(prev=='A') {
            int a = 0;
            a = (a + ans1)%mod;
            a = (a + ans2)%mod;
            a = (a + ans3)%mod;
            a = (a + ans4)%mod;
            a = (a + ans5)%mod;
            return dp[i][prev]=a%mod;
        }
        if(prev=='a') {
            return dp[i][prev]=ans2%mod;
        }
        if(prev=='e') {
            int a = 0;
            a = ((a + ans1)%mod + (a + ans3)%mod)%mod;
            return dp[i][prev]=a;
        }
        if(prev=='i') {
            int a = 0;
            a = (a + ans1)%mod;
            a = (a + ans2)%mod;
            a = (a + ans4)%mod;
            a = (a + ans5)%mod;
            return dp[i][prev]=a%mod;
        }
        if(prev=='o') {
             int a = 0;
            a = (a + ans3)%mod;
            a = (a + ans5)%mod;
            return dp[i][prev]=a%mod;
        }
        return dp[i][prev]=ans1%mod;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n,'A');
    }
};