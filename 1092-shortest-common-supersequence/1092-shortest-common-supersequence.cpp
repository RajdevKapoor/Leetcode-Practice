class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=1;i<n+1;i++) {
            for (int j=1;j<m+1;j++) {
                if (str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m,k=dp[n][m];
        string s=str1.substr(0,k),ans;
        while (k) {
            if (dp[i][j]==dp[i-1][j]) i--;
            else if (dp[i][j]==dp[i][j-1]) j--;
            else {
                s[k-1]=str1[i-1];
                i--;j--;k--;
            }
        }
        i=0,j=0,k=0;
        while (true) {
            while (i<n&&str1[i]!=s[k]) {
                ans+=str1[i];
                i++;
            }
            while (j<m&&str2[j]!=s[k]) {
                ans+=str2[j];
                j++;
            }
            if (k<dp[n][m]) {
                ans+=s[k];
                i++;j++;k++;
            }
            if (ans.size()==n+m-dp[n][m]) break;
        }
        return ans;
    }
};