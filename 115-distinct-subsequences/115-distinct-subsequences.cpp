class Solution {
public:
    vector<vector<unsigned long long>> dp;
    
    int solve(string &s, string &t, int i, int j){
        if(j == -1) return 1;
        if(i == -1) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = solve(s, t, i-1, j-1) + solve(s, t, i-1, j);
        }else{
            return dp[i][j] = solve(s, t, i-1, j);
        }
    }
    
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        dp.resize(n+1, vector<unsigned long long>(m+1, -1));
        return solve(s, t, n-1, m-1);
    }
};