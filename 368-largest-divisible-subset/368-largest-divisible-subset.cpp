class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int n = nums.size();
		int hash[n];
		for(int i=0;i<n;i++) hash[i]=i;
		vector<int> dp(n,1);
		for(int ind=1;ind<n;ind++){
			for(int prev=0;prev<ind;prev++){
				if(nums[ind]%nums[prev]==0){
					if(dp[ind]<1+dp[prev]) dp[ind]=1+dp[prev],hash[ind]=prev;
				}
			}
		}
		int res=0,lastInd;
		for(int i=0;i<n;i++){
			if(res<dp[i]) res=dp[i],lastInd=i;
		}
		vector<int> ans(res,-1);
		int k=res-1;
		while(hash[lastInd]!=lastInd){
			ans[k] = nums[lastInd];
			k--;
			lastInd = hash[lastInd];
		}
		ans[0] = nums[lastInd];
		return ans;
	}
};