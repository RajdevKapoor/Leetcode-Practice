class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size()==0) return 0;
        int len = s.size();
        vector<vector<int>> dp (len+1, vector <int>(len+1,0));
        string t=s;
        reverse(s.begin(),s.end());
        for (int i = len - 1; i >= 0; i--) {
            for (int j = len - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};