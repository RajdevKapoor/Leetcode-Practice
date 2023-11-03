class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int ans = 0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]=i;
        }
        
        for(int i=1;i<=k;i++){
            ans=max(ans,n-mp[i]);
        }
        
        return ans;
        
    }
};