class Solution {
public:
    

    int solve(int i,int day, vector<int>&jobDifficulty, vector<vector<int>>&dp)
    {
        if(day == 0)
        {
            int temp = INT_MIN;
            for(int p=i;p<jobDifficulty.size();p++)
            {
                temp = max(temp, jobDifficulty[p]);
            }
            return temp;
        }
        if(dp[i][day] != -1)
        {
            return dp[i][day];
        }
        int temp = INT_MIN;
        int ans = INT_MAX;
        for(int k=i; k<jobDifficulty.size() - day;k++)
        {
            
            temp = max(temp, jobDifficulty[k]);
            
            ans = min(ans, temp + solve(k+1, day-1, jobDifficulty, dp));
        }
        return dp[i][day] = ans;
    }


    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>>dp(1000, vector<int>(1000,-1));
        if(d > jobDifficulty.size())
        {
            return -1;
        }
        return solve(0, d-1, jobDifficulty, dp);
    }
};
