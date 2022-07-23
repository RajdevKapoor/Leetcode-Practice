class Solution {
private:
    int dp[301][301];
    int solve(vector<int>& nums,int low,int high)
    {
        if(low>high)
            return 0;
        if(dp[low][high]!=-1)
            return dp[low][high];
        int maxi=INT_MIN;
        for(int i=low;i<=high;++i)
            maxi=max(maxi,nums[low-1]*nums[i]*nums[high+1]+solve(nums,low,i-1)+solve(nums,i+1,high));
        
        return dp[low][high]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof dp);
        return solve(nums,1,n);
    }
};